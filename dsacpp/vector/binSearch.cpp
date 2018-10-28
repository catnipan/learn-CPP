#include "../vector.h"

template <typename T>
static Rank binSearch(T* A, T const& e, Rank lo, Rank hi) {
  while (lo < hi) {
    Rank mi = (lo + hi) >> 1;
    if (e < A[mi]) {
      hi = mi;
    } else if (A[mi] < e) {
      lo = mi + 1;
    } else {
      return mi;
    }
  }
  return -1;
}