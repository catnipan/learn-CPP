#include "./vector.h"
#include "./make_int_vector.cpp"
#include "./fib.h"

#include <iostream>

using namespace std;

template <typename T> struct Increase {
  virtual void operator() (T& e) { e++; }
};
template <typename T> void increase(Vector<T>& V) {
  auto inc = Increase<T>();
  V.traverse(inc);
}

int main() {
  // int ia[]{1,1,1,1,1,1,2,2,2,2,2,3,3,3,3,4,4,4,7,7,7,8,9,10};
  // Vector<int> iv(ia, sizeof(ia) / sizeof(*ia));

  // iv.show();
  // iv.uniquify();
  // iv.show();

  // int ia1[]{1,2,4,7,15,23,30,49,56,57,67,87,98,103,122,134};
  // Vector<int> iv1(ia1, sizeof(ia1) / sizeof(*ia1));
  // cout << iv1.search(103) << endl;

  int ia2[]{1,4,34,34,3,4,5,1234,12,54,235,23,52,3,623,52,423};
  Vector<int> iv2(ia2, sizeof(ia2) / sizeof(*ia2));
  iv2.show();
  iv2.sort();
  iv2.show();
}