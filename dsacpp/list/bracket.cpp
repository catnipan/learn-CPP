#include "../list.h"

template <typename T>
T& List<T>::operator[] (Rank r) const {
  ListNodePosi(T) p = first();
  while (0 < r--) {
    p = p -> succ;
  }
  return p -> data;
}