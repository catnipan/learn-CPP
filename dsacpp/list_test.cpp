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
  // List<int> x{4,3,1};
  // x.flatMap(fmapFunction).show();

  // List<int> xxx{1,2,2,2,3,3,3,4,4,6,7,8,9};
  // cout << xxx << endl;
  // cout << xxx.search(7) -> data << endl;
  List<int> yyy{3,2,4,1};
  cout << yyy << endl;
  yyy.sort();
  cout << yyy << endl;
  // cout << yyy.selectMax(yyy.first(), 1)->data << endl;

}
