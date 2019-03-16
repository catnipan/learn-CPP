#pragma once

#include "../b_tree.h"

template <typename T>
void BTree<T>::solveOverflow(BTNodePosi(T) v) {
  if (_order >= v->child.size()) return; // no overflow

  // create a new node containing the right half nodes
  // now the node has (_order + 1) child
  Rank s = _order / 2;
  // _order = 3
  //  x x
  // o o o
  // s = 3 / 2 = 1
  // remove all (s,~)
  //  x X x'
  // o o o' o'
  // v->child.remove(2)
  // j = [0, 1)
  // v->key.remove(2);
  // u: x'
  //  o' o'
  BTNodePosi(T) u = new BTNode<T>();
  for (Rank j = 0; j < _order-s-1; j++) {
    u->child.insert(j, v->child.remove(s+1));
    u->key.insert(j, v->key.remove(s+1));
  }
  u->child[_order-s-1] = v->child.remove(s + 1);
  if (u->child[0]) {
    for (Rank j = 0; j < _order - s; j++) {
      u->child[j]->parent = u;
    }
  }

  //  |
  //  v

  //  |
  //  p
  //  |
  //  v
  BTNodePosi(T) p = v->parent;
  if (!p) { // root overflow
    _root = p = new BTNode<T>();
    p->child[0] = v;
    v->parent = p;
  }
  Rank r = 1 + p->key.search(v->key[0]);
  // v is one of p's children, r is its rank
  // X will go to be one of parent keys
  p->key.insert(r, v->key.remove(s));
  p->child.insert(r+1, u);
  u->parent = p;
  solveOverflow(p);
}

