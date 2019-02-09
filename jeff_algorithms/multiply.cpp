
#include <iostream>

using namespace std;

int multiply(int x, int y) {
  if(x == 0) {
    return 0;
  }
  if(x < 0) {
    return -multiply(-x, y);
  }
  int xx = x / 2;
  int yy = y + y;
  int prod = multiply(xx, yy);
  if (x % 2 == 1) {
    prod += y;
  }
  return prod;
}

int main() {
  cout << multiply(3,4) << endl;
  cout << multiply(4,2) << endl;
  cout << multiply(5,0) << endl;
  cout << multiply(-2,0) << endl;
  cout << multiply(-2,3) << endl;
  cout << multiply(-3,4) << endl;
}