#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxSubArray(vector<int> &nums) {

        vector<int> fx(nums.size(), 0);
        fx[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            fx[i] = nums[i] + fx[i - 1] > 0 ? nums[i] + fx[i - 1] : fx[i - 1];
        }

        return fx[nums.size() - 1];
    }
};
