#include <algorithm>
#include <iostream>

using std::cout;
using std::endl;

void print(int array[], int len) {
  cout << "[";
  for (int i = 0; i < len - 1; i++) {
    cout << array[i] << ", ";
  }
  cout << array[len - 1] << "]" << endl;
}
