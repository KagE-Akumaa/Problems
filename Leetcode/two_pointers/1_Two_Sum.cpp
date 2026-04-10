#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            int v = target - nums[i];
            if (mpp.find(v) != mpp.end()) {
                return {i, mpp[v]};
            }
            mpp[nums[i]] = i;
        }

        return {-1, -1};
    }
};
