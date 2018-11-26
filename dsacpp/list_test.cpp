#include "./list.h"
#include <iostream>

using namespace std;

int main () {
  List<int> ls;
  ls.insertAsFirst(3);
  ls.insertAsFirst(4);
  ls.show();
}
