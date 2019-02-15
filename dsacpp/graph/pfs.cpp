#pragma once

#include "../graph.h"

template <typename Tv, typename Te>
template <typename PU>
void Graph<Tv, Te>::pfs(int s, PU prioUpdater) {
  reset();
  int v = s;
  do {
    if (UNDISCOVERED == status(v)) {
      PFS(v, prioUpdater);
    }
  } while (s != (v = (++v % n)));
}

template <typename Tv, typename Te>
template <typename PU>
void Graph<Tv, Te>::PFS(int s, PU prioUpdater) {
  priority(s) = 0;
  status(s) = VISITED;
  parent(s) = -1;
  while (true) {
    for (int w = firstNbr(s); -1 < w; w = nextNbr(s, w)) {
      prioUpdater(this, s, w);
    }
    // TODO 使用优先级队列优化
    for (int shortest = INT_MAX, w = 0; w < n; w++) {
      if (UNDISCOVERED == status(w)) {
        if (shortest > priority(w)) {
          shortest = priority(w);
          s = w; // 尚未遍历的顶点中加入下一次循环的
        }
      }
    }
    if (VISITED == status(s)) {
      break;
    }
    status(s) = VISITED;
    type(parent(s), s) = TREE;
  }
}