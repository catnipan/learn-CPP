#include "../vector.h"
#include "./fibSearch.cpp"
#include "./binSearch.cpp"

template <typename T>
Rank Vector<T>::search(T const& e, Rank lo, Rank hi) const {
  // switch (rand() % 3) {
  switch (3) {
    case 0:
      return fibSearch(_elem, e, lo, hi);
    case 1:
      return binSearch(_elem, e, lo, hi);
    case 2:
      return binSearch2(_elem, e, lo, hi);
    case 3:
      return binSearch3(_elem, e, lo, hi);
  }
}