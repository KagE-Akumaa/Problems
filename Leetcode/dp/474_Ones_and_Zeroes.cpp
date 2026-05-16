#include <bits/stdc++.h>
using namespace std;

class Solution {
      public:
        int countZeros(string &str) {
                int c = 0;
                for (int i = 0; i < str.size(); i++) {
                        if (str[i] == '0')
                                c++;
                }
                return c;
        }
        int countOnes(string &str) {
                int c = 0;
                for (int i = 0; i < str.size(); i++) {
                        if (str[i] == '1')
                                c++;
                }
                return c;
        }
        int largest(vector<pair<int, int>> &count, vector<string> &strs, int m,
                    int n, int i, vector<vector<vector<int>>> &dp) {
                if (i == strs.size())
                        return 0;
                if (m == 0 && n == 0)
                        return 0;

                if (dp[i][m][n] != -1)
                        return dp[i][m][n];
                if (m >= count[i].first && n >= count[i].second) {
                        int pick = 1 + largest(count, strs, m - count[i].first,
                                               n - count[i].second, i + 1, dp);
                        int not_pick = largest(count, strs, m, n, i + 1, dp);

                        return dp[i][m][n] = max(pick, not_pick);
                }
                return dp[i][m][n] = largest(count, strs, m, n, i + 1, dp);
        }
        int findMaxForm(vector<string> &strs, int m, int n) {
                vector<pair<int, int>> count(strs.size(), {0, 0});

                for (int i = 0; i < strs.size(); i++) {
                        count[i].first = countZeros(strs[i]);
                        count[i].second = countOnes(strs[i]);
                }
                // NOTE: This is memoized version
                // vector<vector<vector<int>>> dp(
                //     strs.size() + 1,
                //     vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
                // return largest(count, strs, m, n, 0, dp);

#if 0
                // NOTE: this is using 3d dp tabulation


                vector<vector<vector<int>>> dp(
                    strs.size() + 1,
                    vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));

                // NOTE: Initializing everything to 0 covers the base condition directly where if i == strs.size() return 0

                // We iterate from backward because we need the i + 1 from the recursive code 
                for (int i = strs.size() - 1; i >= 0; i--) {
                        for (int j = m; j >= 0; j--) {
                                for (int k = n; k >= 0; k--) {
                                        if (j >= count[i].first &&
                                            k >= count[i].second) {
                                                dp[i][j][k] = max(
                                                    1 + dp[i + 1]
                                                          [j - count[i].first]
                                                          [k - count[i].second],
                                                    dp[i + 1][j][k]);
                                        } else {
                                                dp[i][j][k] = dp[i + 1][j][k];
                                        }
                                }
                        }
                }

                return dp[0][m][n];
#endif
                vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

                for (int i = strs.size() - 1; i >= 0; i--) {
                        for (int j = m; j >= 0; j--) {
                                for (int k = n; k >= 0; k--) {
                                        if (j >= count[i].first &&
                                            k >= count[i].second) {
                                                dp[j][k] = max(
                                                    1 + dp[j - count[i].first]
                                                          [k - count[i].second],
                                                    dp[j][k]);
                                        }
                                }
                        }
                }

                return dp[m][n];
        }
};

int main() {
        vector<string> strs = {"10", "0001", "111001", "1", "0"};
        Solution s;
        int m = 5, n = 3;
        cout << s.findMaxForm(strs, m, n) << endl;
}
