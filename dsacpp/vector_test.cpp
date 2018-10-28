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

  for(int i = 0; i < 20; i++) {
    Fib fib{i};
    cout << fib.get() << endl;
  }

}