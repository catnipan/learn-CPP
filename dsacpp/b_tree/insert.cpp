#pragma once

#include "../b_tree.h"

template <typename T>
bool BTree<T>::insert(const T& e) {
  BTNodePosi(T) v = search(e);
  if (v) return false;
  // _hot->key = [2,5,7,9]
  // child =    [x,o,x,x,x]
  // search 3, r = 0 // note that child[r+1] is a nullptr so search stops
  // insert 3 at idx (r+1) = 1, then it become
  // _hot->key = [2,3,5,7,9]
  // child =    [x,o,!,x,x,x]
  // ! is the new nullptr we insert
  Rank r = _hot->key.search(e);
  _hot->key.insert(r + 1, e);
  _hot->child.insert(r + 2, nullptr);
  _size++;
  solveOverflow(_hot);
  return true;
}