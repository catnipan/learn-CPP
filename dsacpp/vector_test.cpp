#include "./vector.h"

int main() {
  int ia[4]{1,3,4,2};
  Vector<int> iv(ia, 4);
  iv.print();
  
  Vector<int> ivr = range(1,100);
  ivr.print();
  ivr.unsort();
  ivr.print();
}