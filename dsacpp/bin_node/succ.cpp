#pragma once

#include "../bin_node.h"

template <typename T>
BinNodePosi(T) BinNode<T>::succ() {
  BinNodePosi(T) s = this;
  if (rc) {
    s = rc;
    while (HasLChild(*s)){
      s = s -> lc;
    }
  } else {
    while (IsRChild(*s)) {
      s = s -> parent;
    }
    s = s -> parent;
  }
  return s;
}