#include <iostream>
#include "./avl_tree.h"

void printInt(const char& i) {
  cout << i << ",";
}

int main() {
  AVLTree<char> avl_tree1{};
  avl_tree1.insert('G');
  avl_tree1.insert('A');
  avl_tree1.insert('B');
  avl_tree1.insert('C');
  avl_tree1.insert('E');
  avl_tree1.insert('D');
  avl_tree1.insert('F');
  avl_tree1.travIn(printInt); cout << endl;
  avl_tree1.remove('C');
  avl_tree1.remove('A');
  avl_tree1.remove('D');
  avl_tree1.travIn(printInt); cout << endl;
}