#include <bits/stdc++.h>
using namespace std;

class Solution {
      public:
        int helper(vector<int> &coins, int amount, int i,
                   vector<vector<int>> &dp) {
                if (amount == 0)
                        return 1;

                if (i >= coins.size()) {
                        return 0;
                }

                if (dp[i][amount] != -1)
                        return dp[i][amount];
                if (amount >= coins[i]) {
                        int pick = helper(coins, amount - coins[i], i, dp);
                        int not_pick = helper(coins, amount, i + 1, dp);

                        return dp[i][amount] = pick + not_pick;
                }
                return dp[i][amount] = helper(coins, amount, i + 1, dp);
        }
        int change(int amount, vector<int> &coins) {
#if 0
                // NOTE: MEMOIZED SOLUTION

                vector<vector<int>> dp(coins.size(),
                                       vector<int>(amount + 1, -1));
                return helper(coins, amount, 0, dp);
#endif
#if 0
                // NOTE: TABULATION SOLUTION

                vector<vector<unsigned int>> dp(coins.size() + 1,
                                       vector<unsigned int>(amount + 1, 0));

                for (int i = 0; i < dp.size(); i++) {
                        dp[i][0] = 1;
                }

                for (int i = coins.size() - 1; i >= 0; i--) {
                        for (int a = 1; a <= amount; a++) {
                                if (a >= coins[i]) {
                                        dp[i][a] =
                                            dp[i][a - coins[i]] + dp[i + 1][a];
                                } else {
                                        dp[i][a] = dp[i + 1][a];
                                }
                        }
                }
                return dp[0][amount];
#endif
                vector<unsigned int> dp(amount + 1, 0);
                dp[0] = 1;

                for (int i = coins.size() - 1; i >= 0; i--) {
                        for (int a = 1; a <= amount; a++) {
                                if (a >= coins[i]) {
                                        dp[a] = dp[a - coins[i]] + dp[a];
                                }
                        }
                }

                return dp[amount];
        }
};

int main() {
        vector<int> coins{1, 2, 5};
        int amount = 5;

        Solution s;

        cout << s.change(amount, coins) << endl;
}
