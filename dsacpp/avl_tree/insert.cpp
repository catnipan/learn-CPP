#pragma once

#include "../avl_tree.h"

template <typename T>
BinNodePosi(T) AVLTree<T>::insert(const T& e) {
  BinNodePosi(T) & x = this->search(e);
  if (x) return x;
  BinNodePosi(T) xx = x = new BinNode<T>(e, this->_hot);
  this->_size++;
  for (BinNodePosi(T) g = this->_hot; g; g = g -> parent) {
    if (!AvlBalanced(*g)) {
      FromParentTo(*g) = this->rotateAt(tallerChild(tallerChild(g)));
      // after this adjustment
      // height of g's ancestors remains unchanged, we could break and stop tracing upward
      break;
    } else {
      this->updateHeight(g);
    }
  }
  return xx;
}

