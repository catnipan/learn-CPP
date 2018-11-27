#include "../list.h"

template <typename T>
template <typename S>
List<S> List<T>::map(S (* mapFunc) (const T&)) {
  List<S> result;
  for (ListNodePosi(T) p = header -> succ; p != trailer; p = p -> succ) {
    result.insertAsLast(mapFunc(p -> data));
  }
  return result;
}