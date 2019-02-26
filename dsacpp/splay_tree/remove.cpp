#pragma once

#include "../splay_tree.h"

template <typename T>
bool SplayTree<T>::remove(const T& e) {
  if (!this->_root || (e != search(e)->data)) {
    return false;
  }
  // else we find the node
  BinNodePosi(T) w = this->_root;
  if (!HasLChild(*this->_root)) {
    // w
    //   a
    //     b
    this->_root = this->_root->rc;
    if (this->_root) {
      this->_root->parent = nullptr; // set new root's parent as nullptr
    }
  } else if (!HasRChild(*this->_root)) {
    //     w
    //   a
    // b
    this->_root = this->_root->lc;
    if (this->_root) {
      this->_root->parent = nullptr;
    }
  } else {
    //    w
    //  a   b
    // ..   ..
    BinNodePosi(T) lTree = this->_root->lc;
    lTree->parent = nullptr;
    this->_root->lc = nullptr;
    // cut out the lTree temporarily
    this->_root = this->_root -> rc;
    this->_root->parent = nullptr;
    // remove root w
    this->search(w->data);
    // search fail, but now root is the succ node larger than w
    this->_root->lc = lTree;
    lTree->parent = this->_root;
  }
  release(w -> data);
  release(w);
  this->_size--;
  if (this->_root) {
    this->updateHeight(this->_root);
  }
  return true;
}