// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

// Find the sum of all the multiples of 3 or 5 below 1000.

#include <iostream>

using namespace std;

int calc_sum(int factor, int max) {
  // last one is how much ?
  const int last_idx = (max - 1) / factor;
  // 1..last_idx
  const int res = (1 + last_idx) * last_idx * factor / 2;
  cout << factor << "\t" << res << endl;
  return res;
}

int calc_3_5(int max) {
  return calc_sum(3, max) + calc_sum(5, max) - calc_sum(15, max);
}

int main() {
  cout << calc_3_5(1000) << endl;
}