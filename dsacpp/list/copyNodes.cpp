#include "../list.h"

template <typename T>
void List<T>::copyNodes (ListNodePosi(T) p, int n) {
  init();
  while (n--) {
    insertAsLast(p->data);
    p = p->succ;
  }
}