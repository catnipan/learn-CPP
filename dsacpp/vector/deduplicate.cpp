#include "../vector.h"

template <typename T> int Vector<T>::deduplicate() {
  int oldSize = _size;
  Rank i = 1;
  while (i < _size) {
    (find(_elem[i], 0,  i) < 0) ? i++ : remove(i);
  }
  return oldSize - _size;
}

// each call of find takes O(n)
// in total it's O(n^2)

// TODO
// store each element we meet in a set (only if data type T can be compared)