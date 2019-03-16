#pragma once

#include "../bin_search_tree.h"

template <typename T> BinNodePosi(T) BinSearchTree<T>::rotateAt(BinNodePosi(T) v) {
  BinNodePosi(T) p = v -> parent;
  BinNodePosi(T) g = p -> parent;
  if (IsLChild(*p)) {
    if (IsLChild(*v)) {
      //     g
      //   p
      // v
      p -> parent = g -> parent;
      return connect34(v, p, g, v->lc, v->rc, p->rc, g->rc);
    } else {
      //     g
      // p
      //   v
      v -> parent = g -> parent;
      return connect34(p, v, g, p->lc, v->lc, v->rc, g->rc);
    }
  } else {
    if (IsRChild(*v)) {
      // g
      //   p
      //     v
      p -> parent = g -> parent;
      return connect34(g, p, v, g->lc, p->lc, v->lc, v->rc);
    } else {
      // g
      //      p
      //   v
      v -> parent = g -> parent;
      return connect34(g, v, p, g->lc, v->lc, v->rc, p->rc);
    }
  }
}