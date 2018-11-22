#include "../vector.h"

template <typename T>
void Vector<T>::sort(Rank lo, Rank hi) {
  switch (1) {
    case 0:
      bubbleSort(lo, hi);
    case 1:
      mergeSort(lo, hi);
  }
}