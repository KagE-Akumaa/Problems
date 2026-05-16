#include <bits/stdc++.h>
using namespace std;
// OBSERVATION: "Minimize the difference between two groups" always reduces to
// "find the subset closest to total/2"
// Let's suppose we have array a , b, c, d and we want the minimum value after
// smashing - so the solution may be a - b , c - d and then the resultant x - y
// -> ans so effectively this means that (a + c) - (b + d) will also gives the
// same result. So, if we take (a + c) as S1 and (b + d) as S2
// so -> S1 - S2 should be minimum we know that S1 + S2 = total_sum
// S1 = total_sum - S2 put that in equation (1)
// total_sum - S2 - S2 should be minimum or
// total_sum - 2*S2 should be minimum and it can be minimum when we can achieve
// a sum of total_sum / 2 if possbile or the closest to this, So this problem
// reduces to find the maximum sum closest or equal to total_sum / 2 and the
// answer will be total_sum - 2*S2
class Solution {
      public:
        int findSum(vector<int> &stones, int target, int i,
                    vector<vector<int>> &dp) {
                if (i == stones.size()) {
                        return 0;
                }

                if (dp[i][target] != -1)
                        return dp[i][target];
                if (target >= stones[i]) {
                        int pick =
                            stones[i] +
                            findSum(stones, target - stones[i], i + 1, dp);

                        int not_pick = findSum(stones, target, i + 1, dp);

                        return dp[i][target] = max(pick, not_pick);
                }
                return dp[i][target] = findSum(stones, target, i + 1, dp);
        }
        int lastStoneWeightII(vector<int> &stones) {
                int total_sum = accumulate(stones.begin(), stones.end(), 0);

                int target = total_sum / 2;

                //  NEED TO FIND THE SUBSET WHICH CAN PRODUCE SUM = total_sum /
                //  2 or closer to this

#if 0
                // NOTE: This is memoized

                vector<vector<int>> dp(stones.size(),
                                       vector<int>(target + 1, -1));
                int val = findSum(stones, target, 0, dp);

                return total_sum - 2 * val;
#endif
#if 0 
                // NOTE: This is tabulation 2d

                vector<vector<int>> dp(stones.size(),
                                       vector<int>(target + 1, 0));

                for (int t = 0; t < dp[0].size(); t++) {
                        if (t >= stones[0]) {
                                dp[0][t] = stones[0];
                        }
                }

                dp[0][0] = 0;

                for (int i = 1; i < stones.size(); i++) {
                        for (int t = 1; t < dp[i].size(); t++) {
                                if (t >= stones[i]) {
                                        dp[i][t] =
                                            max(stones[i] +
                                                    dp[i - 1][t - stones[i]],
                                                dp[i - 1][t]);
                                } else {
                                        dp[i][t] = dp[i - 1][t];
                                }
                        }
                }

                int val = dp[stones.size() - 1][target];

                return total_sum - 2 * val;
#endif
                // NOTE: This is 1d dp optimization

                vector<int> dp(target + 1, 0);

                for (int i = 0; i < stones.size(); i++) {
                        for (int t = dp.size() - 1; t >= 0; t--) {
                                if (t >= stones[i]) {
                                        dp[t] =
                                            max(stones[i] + dp[t - stones[i]],
                                                dp[t]);
                                }
                        }
                }
                int val = dp[target];

                return total_sum - 2 * val;
        }
};
