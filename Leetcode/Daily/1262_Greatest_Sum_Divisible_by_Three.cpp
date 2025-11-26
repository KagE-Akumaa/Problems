#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxSumDivThree(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int ans = INT_MIN;

    if (sum % 3 == 0)
      return sum;

    // For every element we sub from maxSum
    for (int i = 0; i < nums.size(); i++) {
      int val = sum - nums[i];
      if (val % 3 == 0)
        ans = max(val, ans);
      else
        ans = max(ans, 0);
    }
    return ans;
  }
};
