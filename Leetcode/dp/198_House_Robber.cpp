#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
#if 0
        // NOTE: Using O(n) space
        vector<int> dp(n, 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[n - 1];
#endif
        // NOTE: using constant space

        int a = nums[0];
        int b = max(nums[0], nums[1]);

        int c = 0;
        for (int i = 2; i < n; i++) {
            c = max(nums[i] + a, b);
            a = b;
            b = c;
        }
        return c;
    }
};
