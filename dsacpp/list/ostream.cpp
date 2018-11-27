#include "../list.h"

#include <iostream>

template <typename T>
std::ostream& operator<<(std::ostream& out, const List<T>& ls) {
  ListNodePosi(T) p = (ls.header) -> succ;
  out << "⊘ ↔ ";
  while (p != ls.trailer) {
    out << p -> data << " ↔ ";
    p = p -> succ;
  }
  out << "⊘";
  return out;
}