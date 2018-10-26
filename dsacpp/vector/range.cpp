#include "../vector.h";

Vector<int> range(int lo, int hi) {
  int len = hi - lo;
  int ia[len];
  for (int i = 0; i < len; i++) {
    ia[i] = lo + i;
  }
  Vector<int> int_vector(ia, len);
  return int_vector;
}
