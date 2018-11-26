#include "../list.h"

template <typename T>
void List<T>::init() {
  header = new ListNode<T>;
  trailer = new ListNode<T>;
  header->succ = trailer;
  header->pred = nullptr;
  trailer->pred = header;
  trailer->succ = nullptr;
  _size = 0;
}