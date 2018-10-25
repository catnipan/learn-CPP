#include <iostream>
#include <vector>
#include <map>
#include "./util/print_int_vector.h"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numIdxMap;
        vector<int> result;
        int halfTarget = target / 2;
        vector<int> twoHalfTargetIdxs;
        for (int idx = 0; idx < nums.size(); idx++) {
          int currNum = nums[idx];
          if (currNum == halfTarget) {
            twoHalfTargetIdxs.push_back(idx);
          } else {
            numIdxMap.insert({ currNum, idx });
          }
        }
        if (twoHalfTargetIdxs.size() == 2) {
          return twoHalfTargetIdxs;
        }
        for (int idx = 0; idx < nums.size(); idx++) {
          auto cp = numIdxMap.find(target - nums[idx]);
          if (cp != numIdxMap.end()) {
            result.push_back(idx);
            result.push_back(cp->second);
            return result;
          }
        }
        return result;
    }
};

int main() {
  Solution s;
  vector<int> nums{3,3,2,4};
  int target = 6;
  print(s.twoSum(nums, target));
}

// g++ ./1_two_sum.cpp ./util/print_int_vector.cpp -std=c++11 -o ./build/1_two_sum && ./build/1_two_sum