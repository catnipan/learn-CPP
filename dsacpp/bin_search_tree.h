#pragma once

#include "./bin_tree.h"

template <typename T>
class BinSearchTree : public BinTree<T>
{
protected:
  BinNodePosi(T) _hot;
  BinNodePosi(T) connect34(
      BinNodePosi(T), BinNodePosi(T), BinNodePosi(T),
      BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T));
  BinNodePosi(T) rotateAt(BinNodePosi(T) x);

public:
  virtual BinNodePosi(T) & search(const T &e);
  virtual BinNodePosi(T) insert(const T &e);
  virtual bool remove(const T &e);
};


#include "bin_search_tree/search.cpp"
#include "bin_search_tree/insert.cpp"
#include "bin_search_tree/remove.cpp"
#include "bin_search_tree/connect34.cpp"
#include "bin_search_tree/rotateAt.cpp"