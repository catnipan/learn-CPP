#include "../vector.h"

template <typename T>
Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const {
  while (lo < hi) {
    if (e == _elem[hi]) {
      break;
    }
    hi--;
  }
  return hi;
}
