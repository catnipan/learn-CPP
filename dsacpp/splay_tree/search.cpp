#pragma once

#include "../splay_tree.h"

template <typename T>
BinNodePosi(T)& SplayTree<T>::search(const T& e) {
  BinNodePosi(T) p = searchIn(this->_root, e, this->_hot = nullptr);
  this->_root = splay((p ? p : this->_hot));
  return this->_root;
}

