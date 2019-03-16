#include "../splay_tree.h"

template <typename NodePosi>
inline void attachAsLChild(NodePosi p, NodePosi lc) {
  p -> lc = lc;
  if (lc) lc -> parent = p;
}

template <typename NodePosi>
inline void attachAsRChild(NodePosi p, NodePosi rc) {
  p -> rc = rc;
  if (rc) rc -> parent = p;
}

template <typename T>
BinNodePosi(T) SplayTree<T>::splay(BinNodePosi(T) v) {
  if (!v) return nullptr;

  BinNodePosi(T) p;
  BinNodePosi(T) g;

  while (((p = v -> parent) && (g = p -> parent))) {
    BinNodePosi(T) gg = g -> parent;
    if (IsLChild(*v)) {
      if (IsLChild(*p)) {
        //     g
        //   p
        // v
        attachAsLChild(g, p -> rc);
        attachAsLChild(p, v -> rc);
        attachAsRChild(p, g);
        attachAsRChild(v, p);
        // v
        //   p
        //     g
      } else {
        // g
        //      p
        //   v
        attachAsLChild(p, v -> rc);
        attachAsRChild(g, v -> lc);
        attachAsLChild(v, g);
        attachAsRChild(v, p);
        //   v
        // g   p
      }
    } else {
      if (IsRChild(*p)) {
        // g
        //   p
        //     v
        attachAsRChild(g, p -> lc);
        attachAsRChild(p, v -> lc);
        attachAsLChild(p, g);
        attachAsLChild(v, p);
        //     v
        //   p
        // g
      } else {
        //     g
        // p
        //   v
        attachAsRChild(p, v -> lc);
        attachAsLChild(g, v -> rc);
        attachAsRChild(v, g);
        attachAsLChild(v, p);
        //   v
        // p   g
      }
    }
    if (!gg) {
      v -> parent = nullptr;
    } else {
      (g == gg -> lc) ? attachAsLChild(gg, v) : attachAsRChild(gg, v);
    }
    this->updateHeight(g);
    this->updateHeight(p);
    this->updateHeight(v);
  }
  if ((p = v -> parent)) {
    if (IsLChild(*v)) {
      attachAsLChild(p, v -> rc);
      attachAsRChild(v, p);
    } else {
      attachAsRChild(p, v -> lc);
      attachAsLChild(v, p);
    }
    this->updateHeight(p);
    this->updateHeight(v);
  }
  v -> parent = nullptr;
  return v;
}