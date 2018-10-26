#include <iostream>

using namespace std;

int fib(int n) {
  return (n < 2) ? n : fib(n - 1) + fib(n - 2);
}

int _fib1(int n, int& prev) {
  if (n == 0) {
    prev = 1;
    return 0;
  } else {
    int prevPrev;
    prev = _fib1(n - 1, prevPrev);
    return prevPrev + prev;
  }
}

int fib1(int n) {
  int prev;
  return _fib1(n, prev);
}

int fib2(int n) {
  int f = 0, g = 1;
  while (0 < n--) {
    g += f;
    f = g - f;
  }
  return f;
}

int main() {
  for (int i = 0; i < 30; i++) {
    int prev;
    // cout << i << ":" << fib(i) << endl;
    cout << i << ":" << fib2(i) << endl;
  }
}