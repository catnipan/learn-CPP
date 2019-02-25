#include <iostream>
#include "./bin_search_tree.h"

using namespace std;

void printInt(const int& i) {
  cout << i << ",";
}

int main() {
  BinSearchTree<int> bst1{};
  bst1.insert(3);
  bst1.insert(5);
  bst1.insert(9);
  bst1.insert(1);
  bst1.insert(12);
  bst1.insert(15);
  bst1.travIn(printInt); cout << endl;
  bst1.remove(3);
  bst1.remove(5);
  bst1.travIn(printInt); cout << endl;
}