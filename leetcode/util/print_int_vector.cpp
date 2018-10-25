#include <vector>
#include <iostream>

using namespace std;

void print(const vector<int>& xs) {
  cout << "[";
  auto p = xs.begin();
  for(; p != xs.end() - 1; p++) {
    cout << *p << ",";
  }
  cout << *p << "]" << endl;
};