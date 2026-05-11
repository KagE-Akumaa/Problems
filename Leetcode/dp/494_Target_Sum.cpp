#include <asm-generic/errno.h>
#include <bits/stdc++.h>
using namespace std;

class Solution {
      public:
        int find(vector<int> &nums, int i, int target,
                 map<pair<int, int>, int> &mpp) {
                if (i == nums.size() && target == 0) {
                        return 1;
                }
                if (i == nums.size() && target != 0)
                        return 0;

                if (mpp.count({i, target}))
                        return mpp[{i, target}];
                int choosePos = find(nums, i + 1, target - nums[i], mpp);
                // int chooseNeg = find(nums, i + 1, target - (-1 * nums[i]),
                // mpp);
                //  target - (-1 * nums[i])) = target + nums[i]
                int chooseNeg = find(nums, i + 1, target + nums[i], mpp);

                return mpp[{i, target}] = chooseNeg + choosePos;
        }
        int ways(vector<int> &nums, int target, int i,
                 vector<vector<int>> &dp) {
                if (target == 0 && i == nums.size())
                        return 1;
                if (i == nums.size() && target != 0)
                        return 0;

                if (dp[i][target] != -1)
                        return dp[i][target];
                if (target >= nums[i]) {
                        int choose = ways(nums, target - nums[i], i + 1, dp);
                        int not_choose = ways(nums, target, i + 1, dp);

                        return dp[i][target] = choose + not_choose;
                }
                return dp[i][target] = ways(nums, target, i + 1, dp);
        }
        int findTargetSumWays(vector<int> &nums, int target) {
#if 0
                // NOTE: This is using map
                map<pair<int, int>, int> mpp;
                return find(nums, 0, target, mpp);
#endif
                // NOTE: using the technique of shifting p = (s + target)/2;

                int sum = accumulate(nums.begin(), nums.end(), 0);

                // If +1000 is possible so -1000 is also possible
                target = abs(target);
                if (target > sum)
                        return 0;
                if ((target + sum) & 1)
                        return 0;

#if 0
                // NOTE: Now this problem is reduced to can we get a subset sum
                // for s + target / 2 if yes then how many

                vector<vector<int>> dp(nums.size(),
                                       vector<int>((sum + target) / 2 + 1, -1));
                return ways(nums, (sum + target) / 2, 0, dp);
#endif
#if 0
                // NOTE: This is using tabulation

                vector<vector<int>> dp(nums.size(),
                                       vector<int>((sum + target) / 2 + 1, 0));

                if (nums[0] == 0) {
                        dp[0][0] = 2;
                } else {
                        dp[0][0] = 1;
                        if (nums[0] <= (sum + target) / 2)
                                dp[0][nums[0]] = 1;
                }
                for (int i = 1; i < dp.size(); i++) {
                        for (int t = 0; t < dp[i].size(); t++) {
                                if (t >= nums[i]) {
                                        dp[i][t] = dp[i - 1][t - nums[i]] +
                                                   dp[i - 1][t];
                                } else {
                                        dp[i][t] = dp[i - 1][t];
                                }
                        }
                }

                return dp[nums.size() - 1][(sum + target) / 2];
#endif
                vector<int> dp((sum + target) / 2 + 1, 0);

                if (nums[0] == 0) {
                        dp[0] = 2;
                } else {
                        dp[0] = 1;
                        if (nums[0] <= (sum + target) / 2)
                                dp[nums[0]] = 1;
                }

                for (int i = 1; i < nums.size(); i++) {
                        for (int t = dp.size() - 1; t >= 0; t--) {
                                if (t >= nums[i]) {
                                        dp[t] = dp[t - nums[i]] + dp[t];
                                }
                        }
                }

                return dp[dp.size() - 1];
        }
};

int main() {
        vector<int> nums = {1, 1, 1, 1, 1};
        int target = 3;

        Solution s;

        cout << s.findTargetSumWays(nums, target) << endl;
}
