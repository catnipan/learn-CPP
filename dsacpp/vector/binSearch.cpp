#include "../vector.h"
#include <iostream>
using namespace std;

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

template <typename T>
static Rank binSearch2(T* A, T const& e, Rank lo, Rank hi) {
  while (1 < hi - lo) {
    Rank mi = (lo + hi) >> 1;
    (e < A[mi]) ? hi = mi : lo = mi;
  }
  return (e == A[lo]) ? lo : -1;
}

template <typename T>
static Rank binSearch3(T* A, T const& e, Rank lo, Rank hi) {
  while (lo < hi) {
    cout << "[" << lo << "," << hi << ")\t";
    Rank mi = (lo + hi) >> 1;
    cout << "mi: " << mi << " e: " << e << " A[mi]:" << A[mi] << endl;
    (e < A[mi]) ? hi = mi : lo = mi + 1;
  }
  return --lo;
}
