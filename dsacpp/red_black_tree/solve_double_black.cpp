#pragma once

#include "../red_black_tree.cpp"

template <typename T>
void RedBlackTree<T>::solveDoubleBlack(BinNodePosi(T) r) {
  BinNodePosi(T) p = r ? r->parent : _hot;
  if (!p) return;
  BinNodePosi(T) s = (r == p->lc) ? p->rc : p->lc;
  if (IsBlack(s)) {
    BinNodePosi(T) t = nullptr;
    if (IsRed(s->rc)) t = s->rc;
    if (IsRed(s->lc)) t = s->lc;
    if (t) { // BB-1
      RBColor oldColor = p->color;
      auto& fromParentPtr{FromParentTo(*p)};
      BinNodePosi(T) b = fromParentPtr = rotateAt(t);
      if (HasLChild(*b)) {
        b->lc->color = RB_BLACK;
        updateHeight(b->lc);
      }
      if (HasRChild(*b)) {
        b->rc->color = RB_BLACK;
        updateHeight(b->rc);
      }
      b->color = oldColor;
      updateHeight(b);
    } else {
      s->color = RB_RED;
      s->height--;
      if (IsRed(p)) { // BB-2R
        p->color = RB_BLACK;
      } else { // BB-2B
        p->height--;
        solveDoubleBlack(p);
      }
    }
  } else { // BB-3
    s->color = RB_BLACK;
    p->color = RB_RED;
    BinNodePosi(T) t = IsLChild(*s) ? s->lc : s->rc;
    _hot = p;
    auto& fromParentPtr{FromParentTo(*p)};
    fromParentPtr = rotateAt(t);
    solveDoubleBlack(p);
  }
}