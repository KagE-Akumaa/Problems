#include <bits/stdc++.h>
using namespace std;

// NOTE: This is the template for 0-1 knapsack problem all version - >

class Solution {
      public:
        int helper(int w, vector<int> &val, vector<int> &wt, int i) {
                if (i == wt.size() || w == 0)
                        return 0;

                // 2 choice if w >= wt[i] either pick it or skip it
                if (w >= wt[i]) {
                        return max(val[i] + helper(w - wt[i], val, wt, i + 1),
                                   helper(w, val, wt, i + 1));
                } else {
                        return helper(w, val, wt, i + 1);
                }
        }
        int helper(int w, vector<int> &val, vector<int> &wt, int i,
                   vector<vector<int>> &dp) {
                if (i == wt.size() || w == 0) {
                        return 0;
                }

                if (dp[i][w] != -1) {
                        return dp[i][w];
                }
                if (w >= wt[i]) {
                        return dp[i][w] = max(val[i] + helper(w - wt[i], val,
                                                              wt, i + 1, dp),
                                              helper(w, val, wt, i + 1, dp));
                } else {
                        return dp[i][w] = helper(w, val, wt, i + 1, dp);
                }
        }
        int knapsack(int W, vector<int> &val, vector<int> &wt) {
                // code here

#if 0
                // NOTE: This is the recrusive Solution TC - O(2^n)

                return helper(W, val, wt, 0);
#endif

#if 0
                // NOTE: This is the memoized Solution TC - O(n * W) and space
                // is - O(n * W)  + O(n) stack space

                vector<vector<int>> dp(wt.size() + 1, vector<int>(W + 1, -1));

                return helper(W, val, wt, 0, dp);
#endif
                // NOTE: This is the tabulation Solution to get rid of the stack
                // space
#if 0
                vector<vector<int>> dp(wt.size() + 1, vector<int>(W + 1, 0));

                for (int i = 0; i < dp.size(); i++) {
                        dp[i][0] = 0;
                }

                for (int w = 0; w < dp[0].size(); w++) {
                        if (w >= wt[0]) {
                                dp[0][w] = val[0];
                        }
                }

                dp[0][0] = 0;
                for (int i = 1; i < wt.size(); i++) {
                        for (int w = 1; w < dp[i].size(); w++) {
                                if (w >= wt[i]) {
                                        dp[i][w] =
                                            max(val[i] + dp[i - 1][w - wt[i]],
                                                dp[i - 1][w]);
                                } else {
                                        dp[i][w] = dp[i - 1][w];
                                }
                        }
                }

                return dp[wt.size() - 1][W];
#endif
                // NOTE: Using tabulation but 1d dp array
                vector<int> dp(W + 1, 0);

                for (int i = 0; i < wt.size(); i++) {
                        for (int w = dp.size() - 1; w >= 0; w--) {
                                if (w >= wt[i]) {
                                        dp[w] =
                                            max(val[i] + dp[w - wt[i]], dp[w]);
                                }
                                // } else { can be removed i mean what's it
                                // even doing
                                //         dp[w] = dp[w];
                                // }
                        }
                }

                return dp[W];
        }
};
