#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        long long int num = 0;
        list<long long int> pendings{1};
        while (n > 0) {
          long long int newNum;
          do {
            newNum = pendings.front();
            pendings.pop_front();
          } while (newNum == num);
          
          num = newNum;
          pendings.merge(list<long long int>{num * 2, num * 3, num * 5});
          n--;
        }
        return num;
    };
    int nthUglyNumber1(int n) {
      vector<int> result{1};
      int i2 = 0, i3 = 0, i5 = 0;
      while (result.size() < n) {
        result.push_back(
          min(
            result[i2] * 2,
            min(result[i3] * 3, result[i5] * 5)
          )
        );
        if (result.back() == result[i2] * 2) ++i2;
        if (result.back() == result[i3] * 3) ++i3;
        if (result.back() == result[i5] * 5) ++i5;
      }
      return result.back();
    }
    int nthUglyNumber2(int n) {
      static vector<int> result{1};
      static int i2 = 0, i3 = 0, i5 = 0;
      while (result.size() < n) {
        const int next2 = result[i2] * 2;
        const int next3 = result[i3] * 3;
        const int next5 = result[i5] * 5;

        const int next = min(next2, min(next3, next5));

        if (next == next2) i2++;
        if (next == next3) i3++;
        if (next == next5) i5++;

        result.push_back(next);
      }
      return result[n-1];
    }
};

int main() {
  Solution s{};
  for (int i = 21; i >= 10; i--) {
    cout << i << "\t" << s.nthUglyNumber1(i) << "\t" << s.nthUglyNumber2(i) << endl;
  }
}