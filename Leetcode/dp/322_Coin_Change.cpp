
#include <bits/stdc++.h>
using namespace std;

class Solution {
      public:
        int helper(const vector<int> &coins, int amount, int i,
                   vector<vector<int>> &dp) {
                if (amount == 0) {
                        return 0;
                }

                if (i >= coins.size()) {
                        return INT_MAX;
                }

                if (dp[i][amount] != -1) {
                        return dp[i][amount];
                }

                if (amount >= coins[i]) {
                        int pick = helper(coins, amount - coins[i], i, dp);

                        if (pick != INT_MAX) {
                                pick += 1;
                        }

                        int not_pick = helper(coins, amount, i + 1, dp);

                        return dp[i][amount] = min(pick, not_pick);
                }

                return dp[i][amount] = helper(coins, amount, i + 1, dp);
        }
        int coinChange(vector<int> &coins, int amount) {

#if 0
                // NOTE: MEMOIZED Solution

                vector<vector<int>> dp(coins.size(),
                                       vector<int>(amount + 1, -1));

                int val = helper(coins, amount, 0, dp);

                if (val == INT_MAX)
                        return -1;
                return val;
#endif
#if 0  
                // NOTE: TABULATION Solution

                vector<vector<int>> dp(coins.size(),
                                       vector<int>(amount + 1, INT_MAX));

                for (int i = 0; i < coins.size(); i++) {
                        dp[i][0] = 0;
                }

                for (int a = 1; a <= amount; a++) {
                        if (a % coins[0] == 0)
                                dp[0][a] = a / coins[0];
                }
                for (int i = 1; i < coins.size(); i++) {
                        for (int a = 1; a <= amount; a++) {
                                if (a >= coins[i]) {
                                        int take = dp[i][a - coins[i]];
                                        if (take != INT_MAX)
                                                take += 1;
                                        int not_take = dp[i - 1][a];

                                        dp[i][a] = min(take, not_take);
                                } else {
                                        dp[i][a] = dp[i - 1][a];
                                }
                        }
                }
                return dp[coins.size() - 1][amount] == INT_MAX
                           ? -1
                           : dp[coins.size() - 1][amount];
#endif
                vector<int> dp(amount + 1, INT_MAX);
                dp[0] = 0;

                for (int i = 0; i < coins.size(); i++) {
                        for (int a = 1; a <= amount; a++) {
                                if (a >= coins[i]) {
                                        int take = dp[a - coins[i]];
                                        if (take != INT_MAX)
                                                take += 1;
                                        dp[a] = min(take, dp[a]);
                                }
                        }
                }
                return dp[amount] == INT_MAX ? -1 : dp[amount];
        }
};
