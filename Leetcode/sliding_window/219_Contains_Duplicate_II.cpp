#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> mpp;

    for (int i = 0; i < nums.size(); i++) {
      if (mpp.find(nums[i]) != mpp.end()) {
        int j = mpp[nums[i]];
        if (abs(i - j) <= k)
          return true;
      }
      mpp[nums[i]] = i;
    }
    return false;
  }
};
