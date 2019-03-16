#pragma once

#include "../red_black_tree.cpp"

template <typename T>
void RedBlackTree<T>::solveDoubleBlack(BinNodePosi(T) r) {
  BinNodePosi(T) p = r ? r->parent : _hot;
  if (!p) return;
  BinNodePosi(T) // TODO
}