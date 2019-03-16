#pragma once

#include "./bin_search_tree.h"

template <typename T>
class AVLTree: public BinSearchTree<T>
{
public:
  BinNodePosi(T) insert(const T& e);
  bool remove(const T& e);
};

#define Balanced(x) ((stature((x).lc)) == stature((x).rc))
#define BalFac(x) (stature((x).lc) - stature((x).rc)) // balance factor is the difference of height between its left and right child
#define AvlBalanced(x) ((-2 < BalFac(x)) && (BalFac(x) < 2))

#define tallerChild(x) (\
  stature((x)->lc) > stature((x)->rc) ? (x)->lc : (\
  stature((x)->lc) < stature((x)->rc) ? (x)->rc : (\
  IsLChild(*(x)) ? (x)->lc : (x)->rc )\
  )\
)

#include "avl_tree/insert.cpp"
#include "avl_tree/remove.cpp"
