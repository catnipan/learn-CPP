#pragma once

#include "../avl_tree.h"

template <typename T> bool AVLTree<T>::remove(const T& e) {
  BinNodePosi(T) & x = this->search(e);
  if (!x) return false;
  removeAt(x, this->_hot);
  this->_size--;
  for (BinNodePosi(T) g = this->_hot; g; g = g -> parent) {
    if (!AvlBalanced(*g)) {
      auto& fromParentPtr{FromParentTo(*g)};
      g = fromParentPtr = this->rotateAt(tallerChild(tallerChild(g)));
    }
    this->updateHeight(g);
  }
  return true;
}
