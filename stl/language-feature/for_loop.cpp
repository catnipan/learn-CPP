#include <iostream>

using namespace std;

struct C{
  int data;
  // explicit C(const int& i): data(i * 2) {};
  explicit C(const int& i): data(i * 2) {};
};

int main() {
  for (int i: {1, 2, 4, 5, 6}) {
    cout << i << endl;
  }
  cout << "-----" << endl;

  int arr[] = {1, 2, 4, 5};
  for (const int& i: arr) {
    cout << i << endl;
  }

  cout << "-----" << endl;
  cout << *begin(arr) << endl;
  cout << *(end(arr) - 1) << endl;

  cout << "-----" << endl;
  for (const C& c: {5,12,3}) {
    cout << c.data << endl;
  }
}