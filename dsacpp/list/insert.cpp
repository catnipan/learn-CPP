#include "../list.h"

template <typename T>
ListNodePosi(T) List<T>::insertAsFirst(T const& e) {
  return insertAfter(header, e);
  // _size++;
  // return header -> insertAsScc(e);
}

template <typename T>
ListNodePosi(T) List<T>::insertAsLast(T const& e) {
  return insertBefore(trailer, e);
  // _size++;
  // return trailer->insertAsPred(e);
}

template <typename T>
ListNodePosi(T) List<T>::insertAfter(ListNodePosi(T) p, T const& e) {
  _size++;
  return p -> insertAsSucc(e);
}

template <typename T>
ListNodePosi(T) List<T>::insertBefore(ListNodePosi(T) p, T const& e) {
  _size++;
  return p -> insertAsPred(e);
}