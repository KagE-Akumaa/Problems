#include <bits/stdc++.h>
#include <numeric>
using namespace std;

class Solution {
      public:
        int findTarget(vector<int> &arr, int target, int i,
                       vector<vector<int>> &dp) {
                if (target == 0 || i >= arr.size()) {
                        return 0;
                }
                if (dp[i][target] != -1)
                        return dp[i][target];

                if (target >= arr[i]) {
                        int pick = arr[i] +
                                   findTarget(arr, target - arr[i], i + 1, dp);
                        int not_pick = findTarget(arr, target, i + 1, dp);

                        return dp[i][target] = max(pick, not_pick);
                }
                return dp[i][target] = findTarget(arr, target, i + 1, dp);
        }
        int minDifference(vector<int> &arr) {
                // code here
                int total_sum = accumulate(arr.begin(), arr.end(), 0);

                int target = total_sum / 2;

                // NOTE: Now the problem boils down to we just have to find a
                // subset closer to or equal to target and the answer will be
                // total_sum - 2 * val

                // NOTE: MEMOIZED SOLUTION

#if 0
                vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));

                int val = findTarget(arr, target, 0, dp);

                return total_sum - 2 * val;
#endif
#if 0
                // NOTE: THIS IS TABULATION 2D dp

                vector<vector<int>> dp(arr.size(), vector<int>(target + 1, 0));

                if (arr[0] == 0) {
                        dp[0][0] = 0;
                }
                for (int t = 1; t < dp[0].size(); t++) {
                        if (t == arr[0])
                                dp[0][t] = arr[0];

                        else {
                                dp[0][t] = dp[0][t - 1];
                        }
                }

                for (int i = 1; i < dp.size(); i++) {
                        for (int t = 1; t < dp[i].size(); t++) {
                                if (t >= arr[i]) {
                                        dp[i][t] =
                                            max(arr[i] + dp[i - 1][t - arr[i]],
                                                dp[i - 1][t]);
                                } else {
                                        dp[i][t] = dp[i - 1][t];
                                }
                        }
                }
                int val = dp[arr.size() - 1][target];
                cout << val << endl;

                return total_sum - 2 * val;
#endif

                vector<int> dp(target + 1, 0);

                for (int i = 0; i < arr.size(); i++) {
                        for (int t = target; t >= 0; t--) {
                                if (t >= arr[i]) {
                                        dp[t] =
                                            max(arr[i] + dp[t - arr[i]], dp[t]);
                                }
                        }
                }

                int val = dp[target];

                return total_sum - 2 * val;
        }
};

int main() {
        vector<int> arr{1, 9};

        Solution s;

        cout << s.minDifference(arr) << endl;
}
