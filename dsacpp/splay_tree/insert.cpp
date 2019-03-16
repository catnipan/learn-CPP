#pragma once

#include "../splay_tree.h"

template <typename T>
BinNodePosi(T) SplayTree<T>::insert(const T& e) {
  if (!this->_root) {
    this->_size++;
    return this->_root = new BinNode<T>(e);
  }
  if (e == this->search(e)->data) {
    // during search we have uplift this node to the root
    return this->_root;
  }

  this->_size++;
  BinNodePosi(T) t = this->_root;
  //    t
  // lc   rc
  if (this->_root->data < e) {
    t -> parent = this->_root = new BinNode<T>(e, nullptr, t, t -> rc);
    if (HasRChild(*t)) {
      t -> rc -> parent = this->_root;
      t -> rc = nullptr;
    }
  } else {
    t -> parent = this->_root = new BinNode<T>(e, nullptr, t -> lc, t);
    if (HasLChild(*t)) {
      t -> lc -> parent = this->_root;
      t -> lc = nullptr;
    }
  }
  this->updateHeightAbove(t); // although splay tree doesn't care about node's height
  return this->_root;
}