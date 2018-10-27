#include "../vector.h"

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
void Vector<T>::show(Rank lo, Rank hi) {
  cout << "[";
  for (int i = lo; i < hi - 1; i++) {
    cout << _elem[i] << ",";
  }
  cout << _elem[hi - 1] << "]" << endl;
}