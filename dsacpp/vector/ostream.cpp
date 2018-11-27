#include "../vector.h"
#include <iostream>

template <typename S>
std::ostream& operator<<(std::ostream& out, Vector<S>& vc) {
  out << "[ ";
  int i = 0;
  for (; i < vc.size(); i++) {
    out << vc[i] << ", ";
  }
  out << vc[i] << " ]";
  return out;
}
