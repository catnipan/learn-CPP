#pragma once

#include "../bin_search_tree.h"

template <typename T>
static BinNodePosi(T)& searchIn(BinNodePosi(T) & v, const T &e, BinNodePosi(T) & hot)
{
  if (!v || (e == v->data))
    return v;
  hot = v;
  return searchIn(((e < v->data) ? v->lc : v->rc), e, hot);
}

template <typename T> BinNodePosi(T) & BinSearchTree<T>::search(const T& e) {
  return searchIn(this->_root, e, _hot = nullptr);
}
