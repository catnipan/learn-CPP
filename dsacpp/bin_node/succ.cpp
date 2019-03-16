#pragma once

#include "../bin_node.h"

template <typename T>
BinNodePosi(T) BinNode<T>::succ() {
  BinNodePosi(T) s = this;
  if (rc) {
    //  x
    //      r
    //     l
    //    l
    //   l~
    s = rc;
    while (HasLChild(*s)){
      s = s -> lc;
    }
  } else {
    //        p~
    //   p
    //     p
    //      x
    while (IsRChild(*s)) {
      s = s -> parent;
    }
    s = s -> parent;
  }
  return s;
}