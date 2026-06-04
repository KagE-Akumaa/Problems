#include <bits/stdc++.h>
using namespace std;

class Solution {
      public:
        int helper(vector<int> &arr, int sum, int i, vector<vector<int>> &dp) {
                if (sum == 0) {
                        return 1;
                }
                if (i >= arr.size()) {
                        return 0;
                }

                if (dp[i][sum] != -1)
                        return dp[i][sum];

                if (sum >= arr[i]) {
                        int pick = helper(arr, sum - arr[i], i + 1, dp);
                        int not_pick = helper(arr, sum, i + 1, dp);

                        return dp[i][sum] = pick + not_pick;
                }

                return dp[i][sum] = helper(arr, sum, i + 1, dp);
        }
        int countSubset(vector<int> &arr, int k) {
                // code here

                vector<vector<int>> dp(arr.size(), vector<int>(k + 1, -1));
                return helper(arr, k, 0, dp);
        }
};
