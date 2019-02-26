#pragma once

#include "./bin_search_tree.h"

template <typename T>
class SplayTree: public BinSearchTree<T>
{
protected:
  BinNodePosi(T) splay(BinNodePosi(T) v);
public:
  BinNodePosi(T)& search(const T& e);
  BinNodePosi(T) insert(const T& e);
  bool remove(const T& e);
};

#include "splay_tree/splay.cpp"
#include "splay_tree/search.cpp"
#include "splay_tree/insert.cpp"
#include "splay_tree/remove.cpp"