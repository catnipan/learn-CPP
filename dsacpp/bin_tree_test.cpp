#include <iostream>
#include "./bin_tree.h"

void printInt(const int& i) {
  std::cout << i << ", ";
}

int main() {
  BinTree<int> bt{};
  BinNode<int>* root = bt.insertAsRoot(14);
  auto nl = bt.insertAsLC(root, 10);
  auto nll = bt.insertAsLC(nl, 5);
  bt.insertAsRC(nll, 3);
  auto nr = bt.insertAsRC(root, 12);
  bt.insertAsLC(nr, 13);
  bt.insertAsRC(nr, 15);
  std::cout << "-------Pre-order-------" << std::endl;
  bt.travPre(printInt);
  std::cout << std::endl << "--------In-order-------" << std::endl;
  bt.travIn(printInt);
  std::cout << std::endl << "-------Post-order------" << std::endl;
  bt.travPost(printInt);
  std::cout << std::endl << "-------Level-order------" << std::endl;
  bt.travLevel(printInt);
  std::cout << std::endl << "-----------------------" << std::endl;
}