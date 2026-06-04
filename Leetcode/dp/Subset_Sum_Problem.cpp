#include <bits/stdc++.h>
using namespace std;

class Solution {
      public:
        bool check(vector<int> &arr, int sum, int i, vector<vector<int>> &dp) {
                if (sum == 0) {
                        return true;
                }
                if (i >= arr.size())
                        return false;

                if (dp[i][sum] != -1)
                        return dp[i][sum];
                if (sum >= arr[i]) {
                        bool take = check(arr, sum - arr[i], i + 1, dp);
                        bool not_take = check(arr, sum, i + 1, dp);

                        return dp[i][sum] = take || not_take;
                }

                return dp[i][sum] = check(arr, sum, i + 1, dp);
        }

        bool isSubsetSum(vector<int> &arr,
                         int sum) { // code here

#if 0
                // NOTE: MEMOIZED SOLUTION

                vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));
                return check(arr, sum, 0, dp);
#endif

#if 0
                // NOTE: This is Tabulation SOLUTION 

                vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, 0));

                for (int t = 0; t <= sum; t++) {
                        if (t == arr[0]) {
                                dp[0][t] = 1;
                        }
                }

                for (int i = 0; i < arr.size(); i++) {
                        dp[i][0] = 1;
                }

                for (int i = 1; i < arr.size(); i++) {
                        for (int t = 1; t <= sum; t++) {
                                if (t >= arr[i]) {
                                        dp[i][t] = dp[i - 1][t - arr[i]] ||
                                                   dp[i - 1][t];
                                } else
                                        dp[i][t] = dp[i - 1][t];
                        }
                }

                return dp[arr.size() - 1][sum];
#endif
                vector<int> dp(sum + 1, 0);
                dp[0] = 1;

                for (int i = 0; i < arr.size(); i++) {
                        for (int t = sum; t >= 0; t--) {
                                if (t >= arr[i]) {
                                        dp[t] = dp[t - arr[i]] || dp[t];
                                }
                        }
                }
                return dp[sum];
        }
};
int main() {
        vector<int> arr{6, 3, 7, 4, 1, 6, 4, 3, 7};
        int sum = 4;
        Solution s;
        cout << (s.isSubsetSum(arr, sum) == 0 ? "false" : "true") << endl;
}
