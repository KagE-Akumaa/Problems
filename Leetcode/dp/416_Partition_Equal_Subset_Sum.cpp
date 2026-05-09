#include <bits/stdc++.h>
using namespace std;

class Solution {
      public:
        bool isEqual(vector<int> &nums, int n, int total_sum,
                     vector<vector<int>> &dp) {
                if (total_sum == 0) {
                        return true;
                }

                if (n == 0) {
                        if (total_sum - nums[0] == 0) {
                                return true;
                        } else
                                return false;
                }

                if (total_sum < 0) {
                        return false;
                }

                if (dp[n][total_sum] != -1)
                        return dp[n][total_sum];

                bool take = isEqual(nums, n - 1, total_sum - nums[n], dp);
                bool not_take = isEqual(nums, n - 1, total_sum, dp);

                return dp[n][total_sum] = take || not_take;
        }
        bool canPartition(vector<int> &nums) {
#if 0
            // NOTE: this is the memoized Solution
                int n = nums.size();
                int total_sum = accumulate(nums.begin(), nums.end(), 0);

                if (total_sum & 1)
                        return false;

                vector<vector<int>> dp(n, vector<int>(total_sum + 1, -1));

                return isEqual(nums, n - 1, total_sum / 2, dp);
#endif
                int n = nums.size();

                int total_sum = accumulate(nums.begin(), nums.end(), 0);
                vector<vector<int>> dp(n + 1, vector<int>(total_sum + 1, -1));

                for (int i = 0; i < n + 1; i++) {
                        dp[i][0] = 0;
                }

                for (int i = 0; i < total_sum + 1; i++) {
                        dp[0][i] = 0;
                }
        }
};

int main() {
        vector<int> nums{1, 5, 11, 5};

        Solution s;

        cout << s.canPartition(nums) << endl;
}
