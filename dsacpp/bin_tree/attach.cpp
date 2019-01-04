#include "../bin_tree.h"

// insert S as x's left child, assuming that x has no left child
template <typename T>
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>* &S) {
  if ((x -> lc = S -> _root)) {
    x -> lc -> parent = x;
  }
  _size += S -> _size;
  updateHeightAbove(x);
  S -> _root = nullptr;
  S -> _size = 0;
  release(S);
  S = nullptr;
  return x;
}

template <typename T>
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>* &S) {
  if ((x -> rc == S -> root)) {
    x -> rc -> parent = x;
  }
  _size += S -> _size;
  updateHeightAbove(x);
  S -> _root = nullptr;
  S -> _size = 0;
  release(S);
  S = nullptr;
  return x;
}