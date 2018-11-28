#include "../list.h"

// p, p+1, p+2 ... p+n-1
template <typename T>
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p, int n) {
  ListNodePosi(T) max = p;
  for (ListNodePosi(T) curr = p -> succ; n > 1; n--) {
    if (curr -> data > max -> data) {
      max = curr;
    }
    curr = curr -> succ;
  }
  return max;
}
