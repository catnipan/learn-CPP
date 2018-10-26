#include <iostream>

using namespace std;

int power2Base(int n) {
  int pow = 1;
  while (0 < n--) {
    pow <<= 1;
  }
  return pow;
}

inline int sqrt(int a) { return a*a; }
int power2BaseR(int n) {
  if (n == 0) {
    return 1;
  }
  return (n & 1) ? sqrt(power2BaseR(n >> 1)) << 1 : sqrt(power2BaseR(n >> 1));
}

int main() {
  cout << power2Base(10) << endl;
  cout << power2BaseR(10) << endl;
}