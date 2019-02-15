#pragma once

#include "../graph.h"
#include "../stack.h"

template <typename Tv, typename Te>
void Graph<Tv, Te>::bcc(int s) {
  reset();
  int clock = 0;
  int v = s;
  Stack<int> S;
  do {
    if (UNDISCOVERED == status(v)) {
      BCC(v, clock, S);
      S.pop();
    }
  } while (s != (v = (++v % n)));
}

// 利用此处闲置的 fTime 充当 hca
// hca 表示各顶点经后向边能连通的最高祖先
#define hca(x) (fTime(x))

template <typename Tv, typename Te>
void Graph<Tv, Te>::BCC(int v, int& clock, Stack<int>& S) {
  hca(v) = dTime(v) = ++clock;
  status(v) = DISCOVERED;
  S.push(v);
  for (int u = firstNbr(v); -1 < u; u = nextNbr(v, u)) {
    switch (status(u)) {
      case UNDISCOVERED:
        parent(u) = v;
        type(v, u) = TREE;
        BCC(u, clock, S);
        if (hca(u) < dTime(v)) {
          // 遍历返回后，发现 u 通过后向边指向v的真祖先
          hca(v) = min(hca(v), hca(u)); // 则 v 也比如此
        } else { // 否则，以 v 为关节点
          // 弹出 v 以上的元素，弹出的元素组成一个双连通域
          while (v != S.pop());
          S.push(v);
        }
        break;
      case DISCOVERED:
        type(v, u) = BACKWARD;
        if (u != parent(v)) {
          // v 的孩子与 v 的真祖先连通
          hca(v) = min(hca(v), dTime(u));
        }
        break;
      default:
        type(v, u) = (dTime(v) < dTime(u)) ? FORWARD : CROSS;
        break;
    }
  }
  status(v) = VISITED;
}

#undef hca
