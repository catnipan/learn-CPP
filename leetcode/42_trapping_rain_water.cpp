#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    using idx = size_t;
    using hiPair = pair<int, idx>;
private:
    idx findLargestIdx(
      const vector<hiPair>& heightIndexes,
      const function<bool(idx)>& inRightSide
    ) {
      for (idx i = 0; i < heightIndexes.size(); i++) {
        if (inRightSide(heightIndexes[i].second)) {
          return heightIndexes[i].first;
        }
      }
      return 0;
    };
public:
    int trap(vector<int>& height) {
      vector<hiPair> heightIndexList;
      for (idx i = 0; i < height.size(); i++) {
        heightIndexList.push_back(make_pair(height[i], i));
      }
      sort(
        heightIndexList.begin(),
        heightIndexList.end(),
        [](hiPair a, hiPair b) -> bool {
          return (a.first > b.first);
        }
      );
      int trapWaterSize = 0;
      for (idx i = 0; i < height.size(); i++) {
        idx largestLeft = findLargestIdx(
          heightIndexList,
          [i](idx j) -> bool { return ( i > j ); }
        );
        idx largestRight = findLargestIdx(
          heightIndexList,
          [i](idx j) -> bool { return ( i < j ); }
        );
        int possibleHolderHeight = min(largestLeft, largestRight);
        int currentBaseHeight = height[i];
        if (possibleHolderHeight > currentBaseHeight) {
          trapWaterSize += (possibleHolderHeight - currentBaseHeight);
        }
      }
      return trapWaterSize;
    }
};

int main() {
  Solution s{};
  vector<int> input{0,1,0,2,1,0,1,3,2,1,2,1};
  cout << s.trap(input) << endl;
  // for (const auto& i: input) {
  //   cout << i << "\t";
  // }
  // cout << endl;
  // sort(input.begin(), input.end(), decOrder);
  // for (const auto& i: input) {
  //   cout << i << "\t";
  // }
  // cout << endl;
}