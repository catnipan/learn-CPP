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

  Vector<int> iv({1,2,32,12,3,4,34,6,7,45,4,51,2412,412,44});
  cout << iv << endl;

  cout << iv.find(34) << endl;
  // int ia1[]{1,2,4,7,15,23,30,49,56,57,67,87,98,103,122,134};
  // Vector<int> iv1(ia1, sizeof(ia1) / sizeof(*ia1));
  // cout << iv1.search(103) << endl;

  // int ia2[]{1,4,34,34,3,4,5,1234,12,54,235,23,52,3,623,52,423};
  // Vector<int> iv2(ia2, sizeof(ia2) / sizeof(*ia2));
  // iv2.sort();
}