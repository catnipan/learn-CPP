#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_record = 0;
        int len = s.length();
        bool chr_set[256]{false};
        int i = 0;
        int j = 0;
        while (true) {
          if (j == len) {
            break;
          }
          char new_chr = s[j];
          if (chr_set[new_chr]) {
            while (s[i] != new_chr) {
              chr_set[s[i]] = false;
              i++;
            }
            chr_set[s[i]] = false;
            i++;
          } else {
            chr_set[new_chr] = true;
            j++;
          }
          if (j - i > max_record) {
            max_record = j - i;
          }
        }
        return max_record;
    }
};

int main() {
  Solution s{};
  cout << s.lengthOfLongestSubstring("abcabcbb") << endl; // 3
  cout << s.lengthOfLongestSubstring("bbbbb") << endl; // 1
  cout << s.lengthOfLongestSubstring("pwwkew") << endl; // 3
}