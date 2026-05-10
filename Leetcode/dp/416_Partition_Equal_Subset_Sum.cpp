#include <bits/stdc++.h>
using namespace std;

class Solution {
      public:
        bool isPossible(vector<int> &nums, int target, int i,
                        vector<vector<int>> &dp) {
                if (target == 0)
                        return true;
                if (i == nums.size())
                        return false;

                if (dp[i][target] != -1)
                        return dp[i][target];

                if (nums[i] <= target) {
                        bool choose =
                            isPossible(nums, target - nums[i], i + 1, dp);
                        bool not_choose = isPossible(nums, target, i + 1, dp);

                        return dp[i][target] = choose || not_choose;
                } else {
                        return dp[i][target] =
                                   isPossible(nums, target, i + 1, dp);
                }
        }
        bool canPartition(vector<int> &nums) {

                int target_sum = accumulate(nums.begin(), nums.end(), 0);
                if (target_sum & 1) {
                        return false;
                }

#if 0
                vector<vector<int>> dp(nums.size() + 1,
                                       vector<int>(target_sum / 2 + 1, -1));

                return isPossible(nums, target_sum / 2, 0, dp);
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
                int target = target_sum / 2;

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

int main() {
        vector<int> nums{1, 5, 11, 5};
        Solution s;

        cout << s.canPartition(nums) << endl;
}
