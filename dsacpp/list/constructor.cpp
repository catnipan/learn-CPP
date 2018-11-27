#include <initializer_list>
#include "../list.h"

template <typename T>
List<T>::List (ListNodePosi(T) p, int n) {
  copyNodes(p, n);
}

template <typename T>
List<T>::List (List<T> const& L) {
  copyNodes(L.first(), L._size);
}

template <typename T>
List<T>::List (List<T> const& L, int r, int n) {
  copyNodes(L[r], n);
}

template <typename T>
List<T>::List(std::initializer_list<T> il) {
  init();
  for (auto p = il.begin(); p != il.end(); p++) {
    insertAsLast(*p);
  }
};
