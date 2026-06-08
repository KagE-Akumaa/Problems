#include <bits/stdc++.h>

using namespace std;
class Solution {
      public:
        int getMin(const vector<int> &arr, int target, int i,
                   vector<vector<int>> &dp) {
                if (target == 0) {
                        return 0;
                }
                if (i >= arr.size()) {
                        return INT_MAX;
                }

                if (dp[i][target] != -1) {
                        return dp[i][target];
                }

                if (target >= arr[i]) {
                        int pick = getMin(arr, target - arr[i], i, dp);
                        if (pick != INT_MAX)
                                pick += 1;
                        int not_pick = getMin(arr, target, i + 1, dp);

                        return dp[i][target] = min(pick, not_pick);
                }

                return dp[i][target] = getMin(arr, target, i + 1, dp);
        }
        int numSquares(int n) {
                vector<int> arr;

                // Step -1 Get the perfect squares
                for (int i = 1; i <= n; i++) {
                        if (i * i > n) {
                                break;
                        }

                        arr.push_back(i * i);
                }

                // Now the problem is reduced to get the min number required to
                // get the sum = n

#if 0
                // NOTE: MEMOIZED SOLUTION

                vector<vector<int>> dp(arr.size(), vector<int>(n + 1, -1));

                return getMin(arr, n, 0, dp);
#endif
#if 0
                // NOTE: TABULATION Solution

                vector<vector<int>> dp(arr.size(), vector<int>(n + 1, INT_MAX));

                // NOTE: We need to tell the current state how many coins it used to get to the target

                for (int t = 1; t <= n; t++) {
                        if (t % arr[0] == 0)
                                dp[0][t] = t / arr[0];
                }


                for (int i = 0; i < arr.size(); i++) {
                        dp[i][0] = 0;
                }

                for (int i = 1; i < arr.size(); i++) {
                        for (int t = 1; t <= n; t++) {
                                if (t >= arr[i]) {
                                        int pick = dp[i][t - arr[i]];
                                        if (pick != INT_MAX)
                                                pick += 1;
                                        int not_pick = dp[i - 1][t];

                                        dp[i][t] = min(pick, not_pick);
                                } else {
                                        dp[i][t] = dp[i - 1][t];
                                }
                        }
                }

                return dp[arr.size() - 1][n];
#endif
                vector<int> dp(n + 1, INT_MAX);
                dp[0] = 0;

                for (int i = 0; i < arr.size(); i++) {
                        for (int t = 1; t <= n; t++) {
                                if (t >= arr[i]) {
                                        dp[t] = min(1 + dp[t - arr[i]], dp[t]);
                                }
                        }
                }
                return dp[n];
        }
};

int main() {
        int n = 2;

        Solution s;
        cout << s.numSquares(n) << endl;
}
