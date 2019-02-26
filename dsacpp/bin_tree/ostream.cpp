#pragma once

#include <iostream>
#include <utility>
#include "../bin_node.h"
#include "../queue.h"
#include "../vector.h"

// template <typename T>
// template <typename VST>
// void BinNode<T>::travLevel(VST& visit) {
//   Queue<BinNodePosi(T)> Q;
//   Q.enqueue(this);
//   while (!Q.empty()) {
//     BinNodePosi(T) x = Q.dequeue();
//     visit(x -> data);
//     if (HasLChild(*x)) Q.enqueue(x -> lc);
//     if (HasRChild(*x)) Q.enqueue(x -> rc);
//   }
// };

int getIdx(int height, int nth) {
  int treeSizePlus1 = (2 << height);
  return (nth * treeSizePlus1 + (treeSizePlus1 / 2 - 1));
}

inline char show(int i) { return i + '0'; }
inline char show(char chr) { return chr; }

template <typename T>
std::ostream& operator<<(std::ostream& out, BinTree<T>& bt) {
  int treeHeight = bt._root->height;

  Vector<std::string> vstr(treeHeight + 1, treeHeight + 1, string((2 << treeHeight) - 1, ' '));
  Vector<int> vidx(treeHeight + 1, treeHeight + 1, 0);

  Queue<std::pair<BinNodePosi(T), int>> Q;
  BinNodePosi(T) emptyNode = new BinNode<T>;

  Q.enqueue(std::make_pair(bt._root, treeHeight));
  while (true) {
    auto x = Q.dequeue();
    int currHeight = x.second;
    auto currNode = x.first;
    if (currHeight < 0) {
      break;
    }
    
    int idx = vidx[currHeight];
    vstr[currHeight][getIdx(currHeight, vidx[currHeight]++)] = (
      currNode == emptyNode ? ' ' : show(currNode->data)
    );

    int childHeight = currHeight - 1;
    Q.enqueue(std::make_pair(
      (currNode && currNode -> lc) ? currNode -> lc : emptyNode, childHeight));
    Q.enqueue(std::make_pair(
      (currNode && currNode -> rc) ? currNode -> rc : emptyNode, childHeight));
  }

  delete emptyNode;

  for (int h = treeHeight; h > 0; h--) {
    cout << vstr[h] << endl;
  }
  cout << vstr[0];
  return out;
}