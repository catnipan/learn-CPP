#include "./list.h"
#include <iostream>
#include <string>

using namespace std;

int times3(const int& i) {
  return i * 3;
}

string replicateStar(const int& i) {
  string s(i, '*');
  return s;
}

List<int> fmapFunction(const int& i) {
  return {i, i*2};
}

int main () {
  // List<int> ls{1,3,1,1,1,1,2,2,1,4,5,3,4,5,6,7};
  // ListNodePosi(int) x = ls.find(31);
  // ls.show();
  // cout << ls.deduplicate() << endl;
  // ls.show();
  // ls.map(replicateStar).show();

  // List<int> a{1,2,3};
  // List<int> b{4,5,6};
  // List<int> c{7,8,9};
  // List<List<int>> abc{a, b, c};
  // mconcat(abc).show();
  List<int> x{4,3,1};
  x.flatMap(fmapFunction).show();
}
