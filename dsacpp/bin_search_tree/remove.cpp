#pragma once

#include "../bin_search_tree.h"

template <typename T> bool BinSearchTree<T>::remove(const T& e) {
  BinNodePosi(T) & x = search(e);
  if (!x) return false;
  removeAt(x, _hot);
  this->_size--;
  this->updateHeightAbove(_hot);
  return true;
}

template <typename T>
static BinNodePosi(T) removeAt(BinNodePosi(T) & x, BinNodePosi(T) & hot) {
  BinNodePosi(T) w = x; // w will be node to be removed
  BinNodePosi(T) succ = nullptr; // succ will be the only child of w
  if (!HasLChild(*x)) {
    //    |
    //    w
    //  .   r
    succ = x = x -> rc;
  } else if (!HasRChild(*x)) {
    //    |
    //    w
    //  l   .
    succ = x = x -> lc;
  } else {
    w = w -> succ();
    //    |
    //    x
    //  l    r
    //     w
    swap(x -> data, w -> data);
    BinNodePosi(T) u = w -> parent;
    ((u == x) ? u->rc : u->lc) = succ = w -> rc;
  }
  hot = w -> parent; // hot is the removed node's parent
  if (succ) succ -> parent = hot;
  release(w -> data);
  release(w);
  return succ;
}