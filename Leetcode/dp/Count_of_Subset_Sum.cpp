/*
 Count of Subset Sum
Given an array of non-negative integers and a target, count the number of
subsets that sum exactly to the target. Input:  nums = [1, 1, 2, 3], target = 3
Output: 3   // {1,2}, {1,2}, {3}
            */

#include <bits/stdc++.h>
using namespace std;

int ways(vector<int> &nums, int target, int i) {
        if (target == 0)
                return 1;
        if (i == nums.size())
                return 0;

        if (nums[i] <= target) {
                int take = ways(nums, target - nums[i], i + 1);
                int not_take = ways(nums, target, i + 1);

                return take + not_take;
        } else {
                return ways(nums, target, i + 1);
        }
}
int ways(vector<int> &nums, int target, int i, vector<vector<int>> &dp) {
        if (target == 0) {
                return 1;
        }
        if (i == nums.size()) {
                return 0;
        }

        if (dp[i][target] != -1) {
                return dp[i][target];
        }

        if (nums[i] <= target) {
                int take = ways(nums, target - nums[i], i + 1, dp);
                int not_take = ways(nums, target, i + 1, dp);

                return dp[i][target] = take + not_take;
        } else {
                return dp[i][target] = ways(nums, target, i + 1, dp);
        }
}
int main() {
        vector<int> nums{1, 1, 2, 3};
        int target = 3;

        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
        // NOTE: This is simple recurssive solution
        cout << ways(nums, target, 0) << endl;

        // NOTE: this is memoized version
        cout << ways(nums, target, 0, dp) << endl;

        // NOTE: this is the tabulation version
        dp.assign(nums.size() + 1, vector<int>(target + 1, -1));

        for (int i = 0; i < target + 1; i++) {
                if (nums[0] == i) {
                        dp[0][i] = 1;
                        continue;
                }
                dp[0][i] = 0;
        }

        for (int i = 0; i < dp.size(); i++) {
                dp[i][0] = 1;
        }

        dp[0][0] = 1;

        for (int i = 1; i < nums.size(); i++) {
                for (int j = 1; j < dp[i].size(); j++) {
                        if (nums[i] <= j) {
                                int take = dp[i - 1][j - nums[i]];
                                int not_take = dp[i - 1][j];

                                dp[i][j] = take + not_take;
                        } else {
                                dp[i][j] = dp[i - 1][j];
                        }
                }
        }

        cout << dp[nums.size() - 1][target] << endl;

        // NOTE: this is the 1d dp version

        vector<int> d(target + 1, 0);

        d[0] = 1;

        for (int &num : nums) {
                for (int i = d.size() - 1; i >= 0; i--) {
                        if (num <= i) {
                                d[i] = d[i] + d[i - num];
                        }
                }
        }

        cout << d[target] << endl;
}
