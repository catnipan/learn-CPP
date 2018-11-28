#include "../list.h"

#include <iostream>
using namespace std;

template <typename T>
void List<T>::selectionSort(ListNodePosi(T) p, int n) {
  ListNodePosi(T) head = p -> pred;
  // mark a position pred to head, because later we may move head node
  ListNodePosi(T) tail = p;
  for (int i = 0; i < n; i++) {
    tail = tail -> succ;
  }
  while (n > 1) {
    ListNodePosi(T) max = selectMax(head -> succ, n);
    cout << "n=" << n << "\t" << "max=" << max->data << endl;
    insertBefore(tail, remove(max));
    tail = tail -> pred;
    n--;
  }
}