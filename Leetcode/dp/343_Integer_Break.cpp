#include <bits/stdc++.h>
using namespace std;

class Solution {
      public:
        int helper(const vector<int> &arr, int target, int i,
                   vector<vector<int>> &dp) {
                if (target == 0)
                        return 1;
                if (i >= arr.size()) {
                        return 0;
                }

                if (dp[i][target] != -1) {
                        return dp[i][target];
                }

                if (target >= arr[i]) {
                        int pick = arr[i] * helper(arr, target - arr[i], i, dp);
                        int not_pick = helper(arr, target, i + 1, dp);

                        return dp[i][target] = max(pick, not_pick);
                }

                return dp[i][target] = helper(arr, target, i + 1, dp);
        }
        int integerBreak(int n) {
                vector<int> arr(n - 1);

                for (int i = 0; i < arr.size(); i++) {
                        arr[i] = i + 1;
                }

#if 0
                vector<vector<int>> dp(arr.size(), vector<int>(n + 1, -1));

                return helper(arr, n, 0, dp);
#endif
                vector<int> dp(n + 1, 1);

                for (int i = 1; i < n; i++) {
                        for (int t = 1; t <= n; t++) {
                                if (t >= i) {
                                        dp[t] = max(i * dp[t - i], dp[t]);
                                }
                        }
                }
                return dp[n];
        }
};
int main() {
        int n = 10;

        Solution s;

        cout << s.integerBreak(n) << endl;
}
