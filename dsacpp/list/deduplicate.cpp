#include "../list.h"

template <typename T>
int List<T>::deduplicate() {
  if (_size < 2) {
    return 0;
  }
  int oldSize = _size;
  ListNodePosi(T) p = header -> succ;
  Rank r = 0;
  while (p != trailer) {
    ListNodePosi(T) q = find( p -> data, r, p);
    if (q) {
      remove(q);
    } else {
      r++;
    }
    p = p -> succ;
  }
  return oldSize - _size;
}