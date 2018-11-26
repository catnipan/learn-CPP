#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    string countAndSay(int n) {
      string s = "1";
      while (n-- > 1) {
        string ns{};
        int i = 0;
        int j = 1;
        while (j <= s.size()) {
          if (s[j] != s[i]) {
            ns = ns + to_string(j - i) + s[i];
            i = j;
          }
          j += 1;
        }
        s = ns;
      }
      return s;
    }
};

int main() {
  Solution s{};
  for (int i = 0; i < 30; i++) {
    cout << i << ":\t" << s.countAndSay(i) << endl;
  }
  // string ns{};
  // ns = ns + to_string(10) + '1';
  // cout << ns << endl;
}