#include "../list.h"

// default param: first(), _size
template <typename T>
void List<T>::sort(ListNodePosi(T) p, int n) {
  switch (2) {
    case 0:
      return insertionSort(p, n);
    case 1:
      return selectionSort(p, n);
    case 2:
      return mergeSort(p, n);
  }
}