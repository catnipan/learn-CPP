#include "../list.h"

template <typename T>
int List<T>::clear() {
  int oldSize = _size;
  while (0 < _size) {
    remove( header->succ );
  }
  return oldSize;
}