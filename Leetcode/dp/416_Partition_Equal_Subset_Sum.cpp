#include <bits/stdc++.h>
using namespace std;

// OBSERVATION: We need to find 2 subset such that there sum should be same so
// technically we need to find a subset whose sum = total_sum / 2 as subset1 +
// subset2 = total_sum and both are equal so 2subset = total_sum or subset =
// total_sum / 2 , Also if total_sum is odd we can not get 2 equal subset
class Solution {
      public:
        bool isPossible(vector<int> &nums, int target, int i,
                        vector<vector<int>> &dp) {
                if (target == 0)
                        return true;
                if (i >= nums.size())
                        return false;

                if (dp[i][target] != -1) {
                        return dp[i][target];
                }
                if (target >= nums[i]) {
                        int pick =
                            isPossible(nums, target - nums[i], i + 1, dp);
                        int not_pick = isPossible(nums, target, i + 1, dp);

                        return dp[i][target] = pick || not_pick;
                }

                return dp[i][target] = isPossible(nums, target, i + 1, dp);
        }
        bool canPartition(vector<int> &nums) {
                int total_sum = accumulate(nums.begin(), nums.end(), 0);

                if (total_sum & 1)
                        return false;

                int target = total_sum / 2;

#if 0
                //NOTE: This is memoized

                vector<vector<int>> dp(nums.size(),
                                       vector<int>(target + 1, -1));

                return isPossible(nums, target, 0, dp);
#endif
#if 0

                // NOTE: This is Bottom up dp - 2d
                vector<vector<int>> dp(nums.size() + 1,
                                       vector<int>(target_sum / 2 + 1, -1));

                for (int i = 0; i < dp.size(); i++) {
                        dp[i][0] = 1;
                }

                for (int i = 0; i < dp[0].size(); i++) {
                        if (nums[0] == i) {
                                dp[0][i] = 1;
                        } else {
                                dp[0][i] = 0;
                        }
                }

                for (int i = 1; i < dp.size() - 1; i++) {
                        for (int j = 1; j < dp[i].size(); j++) {

                                if (nums[i] <= j) {
                                        bool not_choose = dp[i - 1][j];
                                        bool choose = dp[i - 1][j - nums[i]];

                                        dp[i][j] = choose || not_choose;
                                } else {
                                        dp[i][j] = dp[i - 1][j];
                                }
                        }
                }
                return dp[nums.size() - 1][target_sum / 2];
#endif
                // NOTE: This is using 1d dp

                vector<bool> dp(target + 1, false);

                dp[0] = true;
                for (int &num : nums) {
                        for (int i = dp.size() - 1; i >= 0; i--) {
                                if (num <= i) {
                                        dp[i] = dp[i] || dp[i - num];
                                }
                        }
                }

                return dp[target];
        }
};
