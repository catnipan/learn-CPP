#include <tuple>

class GCD {
  int euclid_recursive(int a, int b) {
    if (b == 0) {
      return a;
    }
    return euclid_recursive(b, a % b);
  }

  int euclid_iterative(int a, int b) {
    while (b != 0) {
      int _b = b;
      b = a % b;
      a = _b;
    }
    return a;
  }

public:
  int euclid(int a, int b) {
    return euclid_iterative(a, b);
  }

  std::tuple<int, int, int> euclid_extended(int a, int b) {
    if (b == 0) {
      return {a, 1, 0};
    }
    auto res = euclid_extended(b, a % b);
    int d, x, y;
    std::tie(d, x, y) = res;
    return { d, y, x - (a / b) * y };
  }
};
