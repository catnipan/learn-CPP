#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      int num_size = nums.size() + 1;
      if (num_size == 1) {
        return 1;
      }
      vector<bool> intMap(num_size, true);
      intMap[0] = false;
      for (const int& i: nums) {
        if (i > 0) {
          intMap[i] = false;
        }
      }
      cout << intMap.size() << "[";
      for (const int& i: intMap) {
        cout << i << ",";
      }
      cout << "]" << endl;
      for (int i = 1; i < num_size; i++) {
        if (intMap[i]) {
          return i;
        }
      }
      return num_size;
    }
};

int main() {
  Solution s{};
  // vector<int> v{1, 2, 0};
  // vector<int> v{3, 4, -1, 1};
  vector<int> v0{};
  cout << s.firstMissingPositive(v0) << endl;
  vector<int> v1{1};
  cout << s.firstMissingPositive(v1) << endl;
  vector<int> v2{2};
  cout << s.firstMissingPositive(v2) << endl;
  vector<int> v3{0,1};
  cout << s.firstMissingPositive(v3) << endl;
}