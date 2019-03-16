#include <iostream>
#include "./splay_tree.h"

using namespace std;

void printChar(const char& chr) {
  cout << chr << ",";
}

int main() {
  SplayTree<char> sp_tree1{};
  sp_tree1.insert('A');
  sp_tree1.insert('B');
  sp_tree1.insert('C');
  sp_tree1.insert('D');
  sp_tree1.insert('E');
  cout << sp_tree1 << endl << "-----------------" << endl;
  sp_tree1.search('A');
  cout << sp_tree1 << endl << "-----------------" << endl;
  sp_tree1.remove('D');
  cout << sp_tree1 << endl << "-----------------" << endl;
  // sp_tree1.remove('D');
  // sp_tree1.search('E');
  // sp_tree1.remove('A');
  // sp_tree1.search('B');
  // sp_tree1.remove('B');
  // sp_tree1.remove('C');
  // sp_tree1.search('A');
}