#include "../vector.h"
#include <initializer_list>

template <typename T>
Vector<T>::Vector(std::initializer_list<T> il) {
  copyFrom(il.begin(), 0, il.size());
}