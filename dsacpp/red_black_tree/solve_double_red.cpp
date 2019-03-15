#pragma once

#include "../red_black_tree.h"

template <typename T>
void RedBlackTree<T>::solveDoubleRed(BinNodePosi(T) x) {
  if (IsRoot(*x)) {
    _root->color = RB_BLACK;
    _root->height++;
    return;
  }
  BinNodePosi(T) p = x->parent;
  if (IsBlack(p)) return;
  // double red only when x's parent is also red
  // p is red and g is black
  BinNodePosi(T) g = p->parent;
  BinNodePosi(T) u = uncle(x);
  // ' denotes red node
  if (IsBlack(u)) {
    if (IsLChild(*x) == IsLChild(*p)) { 
      //      g            g
      //    p'  u        u    p'
      // x'                     x'
      // ----------    ------------
      //    p                 p
      // x'   g'           g'   x'
      //        u        u
      p->color = RB_BLACK;
    } else {
      //      g            g
      //  p'     u       u     p'
      //    x'               x'
      // ----------    ------------
      //    x                x
      //  p'  g'           g'  p'
      //         u       u
      x->color = RB_BLACK;
    }
    g->color = RB_RED;
    BinNodePosi(T) gg = g->parent;
    auto& fromParentPtr{FromParentTo(*g)}
    BinNodePosi(T) r = fromParentPtr = rotateAt(x);
    r->parent = gg;
  } else {
    //      g           g         g          g
    //   p'   u'    p'    u'   u'   p'     u'    p'
    // x'             x'              x'       x'
    // ----------------------------------------------
    //      g'          g'        g'         g'
    //   p    u     p     u    u    p      u     p
    // x'             x'              x'       x'
    p->color = RB_BLACK; // p: red -> black
    p->height++;
    u->color = RB_BLACK; // u: red -> black
    u->height++;
    // x g is red
    if (!IsRoot(*g)) g->color = RB_RED;
    solveDoubleRed(g);
  }
}