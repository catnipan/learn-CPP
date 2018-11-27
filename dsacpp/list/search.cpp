#include "../list.h"

// find the largest element that is not greater than e
// not including p
// p-n, p-(n-1), ... p-1, p
template <typename T>
ListNodePosi(T) List<T>::search(T const& e, int n, ListNodePosi(T) p) const {
  while (n >= 0) {
    p = p -> pred;
    if (p -> data <= e) {
      break;
    }
    n--;
  }
  return p;
}
