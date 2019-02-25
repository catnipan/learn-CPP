#include <iostream>
#include "./avl_tree.h"

void printInt(const char& i) {
  cout << i << ",";
}

int main() {
  AVLTree<char> avl_tree1{};
  avl_tree1.insert('A');
  avl_tree1.insert('B');
  avl_tree1.insert('C');
  avl_tree1.travLevel(printInt); cout << endl;
}