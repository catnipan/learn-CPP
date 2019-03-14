#pragma once

#include "../b_tree.h"

template <typename T>
void BTree<T>::solveUnderflow(BTNodePosi(T) v) {
  if ((_order + 1) / 2 <= v->child.size()) return;
  BTNodePosi(T) p = v->parent;
  if (!p) { // now v is the root
    //  .
    // x
    if (!v->key.size() && v->child[0]) {
      // we link _root to v's only child directly
      _root = v->child[0];
      _root->parent = nullptr;
      v->child[0] = nullptr;
      release(v);
    }
    return;
  }
  //  . . . .
  // x x v x x
  Rank r = 0;
  while (p -> child[r] != v) {
    r++;
  }
  if (0 < r) {
    // v is not the leftmost child, then it has left cousin
    BTNodePosi(T) ls = p->child[r - 1];
    if ((_order + 1) < ls->child.size()) {
      // left cousin is fat enough
      v->key.insert(0, p->key[r-1]); // borrow one key from parent
      p->key[r-1] = ls->key.remove(ls->key.size() - 1); // parent borrow one key from left cousin
      v->child.insert(0, ls->child.remove(ls->child.size() - 1));
      // left cousin's rightmost child becoming v's leftmost child
      if (v->child[0]) { // if this child exists, fix its parent as v
        v->child[0]->parent = v;
      }
      return;
    }
  }
  if (p -> child.size() - 1 > r) {
    // v is not the rightmost child, the it has right cousin
    BTNodePosi(T) rs = p->child[r+1];
    if ((_order + 1) / 2 < rs->child.size()) {
      // right cousin is fat enough
      v->key.insert(v->key.size(), p->key[r]); // borrow one key from parent
      p->key[r] = rs->key.remove(0); // parent borrow one key from right cousin
      v->child.insert(v->child.size(), rs->child.remove(0));
      // right cousin's leftmost child becoming v's rightmost child
      if (v->child[v->child.size() - 1]) { // if this child does exist, fix its parent as v
        v->child[v->child.size() - 1]->parent = v;
      }
      return;
    }
  }

  // if borrow is impossible we merge
  if (0 < r) {
    // has a thin left cousin
    BTNodePosi(T) ls = p->child[r - 1];
    ls->key.insert(ls->key.size(), p->key.remove(r - 1));
    p->child.remove(r);
    //
    ls->child.insert(ls->child.size(), v->child.remove(0));
    if (ls->child[ls->child.size() - 1]) {
      ls->child[ls->child.size() - 1]->parent = ls;
    }
    while (!v->key.empty()) {
      ls->key.insert(ls->key.size(), v->key.remove(0));
      ls->child.insert(ls->child.size(), v->child.remove(0));
      if (ls->child[ls->child.size() - 1]) {
        ls->child[ls->child.size() - 1]->parent = ls;
      }
    }
    release(v);
  } else {
    // has a thin right cousin
    BTNodePosi(T) rs = p->child[r+1];
    rs->key.insert(0, p->key.remove(r));
    p->child.remove(r);
    rs->child.insert(0, v->child.remove(v->child.size() - 1));
    if (rs->child[0]) {
      rs->child[0]->parent = rs;
    }
    while (!v->key.empty()) {
      rs->key.insert(0, v->key.remove(v->key.size() - 1));
      rs->child.insert(0, v->child.remove(v->child.size() - 1));
      if (rs->child[0]) {
        rs->child[0]->parent = rs;
      }
    }
    release(v);
  }
  solveUnderflow(p);
  return;
};

