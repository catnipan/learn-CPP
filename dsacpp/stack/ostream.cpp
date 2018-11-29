#include <iostream>
#include "../stack.h"
using std::ostream;


template <typename S>
std::ostream& operator<<(std::ostream& out, Stack<S>& vc) {
  out << "[ ";
  int i = 0;
  for (; i < vc.size() - 1; i++) {
    out << vc[i] << ", ";
  }
  out << vc[i] << " )";
  return out;
}