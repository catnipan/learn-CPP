#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
      if (x < 10 && x > -10) {
        return x;
      }
      if (x == INT_MIN) {
        return 0;
      }
      bool neg{x < 0};
      x = abs(x);
      int num{0};
      int count{};
      while (x) {
        int n = x % 10;
        if (count == 9) {
          if (num > INT_MAX / 10) {
            return 0;
          }
          if (num == INT_MAX / 10 || n > 7) {
            return 0;
          }
        }
        num = num * 10 + n;
        x /= 10;
        count++;
      }

      if (neg) {
        num *= -1;
      }
      return num;
    }
};

int main() {
  Solution s;
  cout << s.reverse(123) << endl;
  cout << s.reverse(-123) << endl;
  cout << s.reverse(120) << endl;
  cout << s.reverse(0) << endl;
  cout << s.reverse(INT_MIN) << endl;
  cout << s.reverse(INT_MAX) << endl;
  // int j = pow(2, 31) - 1;
  // cout << INT_MIN << endl;
  // cout << j << endl;
}