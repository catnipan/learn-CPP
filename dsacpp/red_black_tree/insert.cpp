#pragma once

#include "../red_black_tree.h"

template <typename T>
BinNodePosi(T) RedBlackTree<T>::insert(const T& e) {
  BinNodePosi(T) &x = search(e);
  if (x) return x;
  x = new BinNode<T>(e, _hot, nullptr, nullptr, -1);
  // x initiated as a red node
  _size++;
  solveDoubleRed(x);
  return x ? x : _hot->parent;
}