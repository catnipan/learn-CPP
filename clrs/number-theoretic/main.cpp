#include <iostream>
#include <tuple>
#include "./gcd.cpp"

using namespace std;

int main() {
  cout << GCD().euclid(3, 4) << endl;
  cout << GCD().euclid(12, 60) << endl;
  cout << GCD().euclid(45, 60) << endl;

  int d, x, y;
  std::tie(d, x, y) = GCD().euclid_extended(899, 493);
  cout << d << " = " << 899 << " * " << x << " + " << 493 << " * " << y << endl;
}