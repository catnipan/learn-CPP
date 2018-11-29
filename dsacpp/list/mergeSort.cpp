#include "../list.h"

template <typename T>
void List<T>::mergeSort(ListNodePosi(T)& p, int n) {
  if (n < 2) return;
  int m = n >> 1;
  ListNodePosi(T) q = p;
  for (int i = 0; i < m; i++) {
    q = q -> succ;
  }

  mergeSort(p, m);
  mergeSort(q, n - m);
  merge(p, m, q, n - m);
};

// p, 3
// |
// 1 <-> 3 <-> 5 <-> 2 <-> 4 <-> 10
//                   |
//                   q, 3

// move p forward

//       p, 2
//       |
// 1 <-> 3 <-> 5 <-> 2 <-> 4 <-> 10
//                   |
//                   q, 3

// delete node q, insert that node before p
// move q forward

//             p, 2
//             |
// 1 <-> 2 <-> 3 <-> 5 <-> 4 <-> 10
//                         |
//                         q, 2

// move p forward

//                   p, 1
//                   |
// 1 <-> 2 <-> 3 <-> 5 <-> 4 <-> 10
//                         |
//                         q, 2

// delete node q, insert that node before p
// move q forward

//                         p, 1
//                         |
// 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 10
//                               |
//                               q, 1

// now p == q, break while

//                               p, 1
//                               |
// 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 10
//                               |
//                               q, 1

template <typename T>
void List<T>::merge(ListNodePosi(T)& p, int n, ListNodePosi(T) q, int m) {
  ListNodePosi(T) pp = p -> pred;
  while (m > 0) {
    if ((n > 0) && (p -> data <= q -> data)) {
      // each time p moves forward we decrease n
      p = p -> succ;
      n--;
      if (q == p) {
        break;
      }
    } else {
      // each time q moves forward we decrease m
      q = q -> succ;
      m--;
      insertBefore(p, remove(q -> pred));
    }
  }
  p = pp -> succ;
};
