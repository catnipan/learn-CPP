#pragma once

#include "../red_black_tree.h"

template <typename T>
bool RedBlackTree<T>::remove(const T& e) {
  BinNodePosi(T)& x = search(e);
  if (!x) return false;
  BinNodePosi(T) r = removeAt(x, _hot);
  if (!(--_size)) return true;
  if (!_hot) { // if we remove the root
    _root->color = RB_BLACK; // new root's color should be set black
    updateHeight(_root);
    return true;
  }
  if (BlackHeightUpdated(*_hot)) return true;
  if (IsRed(r)) {
    r->color = RB_BLACK;
    r->height++;
    return true;
  }
  solveDoubleBlack(r);
  return true;
}