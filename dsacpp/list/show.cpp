#include "../list.h"

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
void List<T>::show() {
  ListNodePosi(T) p = header -> succ;
  cout << "|<->";
  while (p != trailer) {
    cout << p -> data << "<->";
    p = p -> succ;
  }
  cout << "|" << endl;
}