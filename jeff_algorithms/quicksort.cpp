#include <iostream>

using namespace std;

size_t partition(int* A, size_t len, size_t p) {
  swap(A[len-1], A[p]);
  size_t l = 0;
  for (size_t i = 0; i < len - 1; i++) {
    if (A[i] <= A[len - 1]) {
      swap(A[l], A[i]);
      l++;
    }
  }
  swap(A[len - 1], A[l]);
  return l;
}

void quickSort(int* A, size_t len) {
  if (len > 1) {
    size_t p = len / 2;
    // choose a pivot element A[p]
    size_t r = partition(A, len, p);
    quickSort(A, r);
    quickSort(A + r + 1, len - r - 1);
  }
}

int main() {
  int x1[]{3,5,4,3,2,1,10,9,6,8};
  // // len = 5;
  // // r = 2;
  // quickSort(x1, 5);
  // int a = 3;
  // int b = 4;
  // swap(x1[0], x1[1]);
  // cout << x1[0] << " " << x1[1] << endl;
  for (int i = 0; i < 10; i++) {
    cout << x1[i] << "\t";
  }
  cout << endl << "-----------" << endl;
  quickSort(x1, 10);
  // cout << "r:" << partition(x1, 10, 4) << endl;
  for (int i = 0; i < 10; i++) {
    cout << x1[i] << "\t";
  }
  cout << endl;
}