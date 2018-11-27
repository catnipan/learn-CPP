#include "../list.h"

template <typename S>
List<S> mconcat(const List<List<S>>& ls) {
  List<S> result;
  for (
        ListNodePosi(List<S>) p = (ls.header) -> succ;
        p != ls.trailer;
        p = p -> succ
      ) {
    for (
      ListNodePosi(S) q = (p -> data).header -> succ;
      q != (p -> data).trailer;
      q = q -> succ
    ) {
      result.insertAsLast(q -> data);
    }
  }
  return result;
}

template <typename T>
template <typename S>
List<S> List<T>::flatMap(List<S> (* mapFunc) (const T&)) {
  return mconcat(map(mapFunc));
}

