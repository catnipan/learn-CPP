#pragma once

#include "./bin_search_tree.h"

template <typename T>
class RedBlackTree: public BinSearchTree<T> {
protected:
  void solveDoubleRed(BinNodePosi(T) x);
  void solveDoubleBlack(BinNodePosi(T) x);
  int updateHeight(BinNodePosi(T) x);
public:
  BinNodePosi(T) insert(const T& e);
  bool remove(const T& e);
};

#define IsBlack(p) (!(p) || (RB_BLACK == (p)->color)) // all 'out' nodes are regarded as black
#define IsRed(p) (!IsBlack(p))
#define BlackHeightUpdated(x) (\
  (stature((x).lc) == stature((x).rc)) && \
  ((x).height == (IsRed(&x) ? stature((x).lc) : stature((x).lc) + 1)\
)

#include "red_black_tree/update_height.cpp"