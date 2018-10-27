#include "../vector.h"

template <typename T>
Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const {
  while ((lo < hi--) && ( e != _elem[hi] ));
  return hi;
}
