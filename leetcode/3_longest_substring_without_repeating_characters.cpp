#include <string>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_record = 0;
        int len = s.length();
        set<char> chr_set;
        int i = 0;
        int j = 0;
        while (true) {
          if (j == len) {
            break;
          }
          char new_chr = s[j];
          if (chr_set.find(new_chr) == chr_set.end()) {
            chr_set.insert(new_chr);
            j++;
          } else {
            // move i forward, delete until delete new_chr before
            while (s[i] != new_chr) {
              chr_set.erase(s[i]);
              i++;
            }
            chr_set.erase(s[i]);
            i++;
          }
          max_record = max(j-i, max_record);
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