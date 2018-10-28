#include "../vector.h"

// template <typename T>
// int Vector<T>::uniquify() {
//   int oldSize = _size;
//   int i = 1;
//   while (i < _size) {
//     _elem[i - 1] = _elem[i] ? remove(i) : i++;
//   }
//   return oldSize - _size;
// }

// in the above algorithm, each call to remove need O(n)
// in total it's O(n^2)

template <typename T>
int Vector<T>::uniquify() {
  Rank i = 0, j = 0;
  while (++j < _size) {
    if (_elem[i] != _elem[j]) {
      _elem[++i] = _elem[j];
    }
  }
  _size = ++i;
  shrink();
  return j - i;
}