#include "../list.h"

template <typename T>
int List<T>::uniquify() {
  int oldSize = _size;
  ListNodePosi(T) p = header -> succ;
  ListNodePosi(T) q = p -> succ;

  // same elements keep last
  // while (q != trailer) {
  //   if (p -> data == q -> data) {
  //     remove(p);
  //   }
  //   p = q;
  //   q = q -> succ;
  // }

  // same element keep first
  while (q != trailer) {
    if (p -> data == q -> data) {
      remove(q);
    } else {
      p = p -> succ; // or same as p = q
    }
    q = p -> succ;
  }

  return _size - oldSize;
}