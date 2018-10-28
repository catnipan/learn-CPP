#include "../fib.h"
#include "../vector.h"

template <typename T>
static Rank fibSearch(T* A, T const& e, Rank lo, Rank hi) {
  Fib fib(hi - lo);
  while (lo < hi) {
    while (hi - lo < fib.get()) {
      fib.prev();
    }
    Rank mi = lo + fib.get() - 1;
    if (e < A[mi]) {
      hi = mi;
    } else if (A[mi] < e) {
      lo = mi + 1;
    } else {
      return mi;
    }
  }
}