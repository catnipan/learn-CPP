#include "./vector.h"

Vector<int> range(int lo, int hi) {
  int len = hi - lo;
  int ia[len];
  for (int i = 0; i < len; i++) {
    ia[i] = lo + i;
  }
  Vector<int> int_vector(ia, len);
  return int_vector;
}

Vector<int> randomIv(int len, int lo, int hi) {
  Vector<int> iv(len);
  int mod = hi - lo;
  for (int i = 0; i < len; i++) {
    iv.insert(lo + (rand() % mod));
  }
  return iv;
}
