#pragma once

#include "../red_black_tree.h"

// height means the 'black' height
template <typename T>
int RedBlackTree<T>::updateHeight(BinNodePosi(T) x) {
  x->height = max(stature(x -> lc), stature(x -> rc));
  return IsBlack(x) ? x->height++ : x->height;
}