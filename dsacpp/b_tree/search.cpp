#pragma once

#include "../b_tree.h"

template <typename T>
BTNodePosi(T) BTree<T>::search(const T& e) {
  BTNodePosi(T) v = _root;
  _hot = nullptr;
  while (v) {
    Rank r = v->key.search(e);
    // r is the largest rank <= e
    // continue to search it in child(r+1)
    // key = [2,5,7,9]
    // search 3 we stop at 2, index is 0
    // go to child 0 + 1 = 1
    // serach 6 we stop at 5, index is 1
    // go to child 1 + 1 = 2
    // search 10 we stop at 9, index is 3
    // go to child 3 + 1 = 4
    if ((r >= 0) && (e == v->key[r])) return v;
    _hot = v;
    v = v->child[r+1];
  }
  return nullptr;
}