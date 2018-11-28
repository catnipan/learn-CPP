#include "../list.h"

template <typename T>
void List<T>::insertionSort(ListNodePosi(T) p, int n) {
  for (int r = 0; r < n; r++) {
    auto positionToInsert = search(p -> data, r, p);
    insertAfter(positionToInsert, p -> data);
    p = p -> succ;
    remove(p -> pred);
  }
}