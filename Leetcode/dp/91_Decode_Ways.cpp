#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // NOTE: This is memoization Solution
    int ways(string &s, int i, vector<int> &dp) {
        if (i == s.size()) {
            return 1;
        }
        if (s[i] == '0')
            return 0;

        if (dp[i] != -1)
            return dp[i];
        dp[i] = ways(s, i + 1, dp);

        if (i + 1 < s.size()) {
            // Means form a number from i to i + 1

            int val = (s[i] - '0') * 10 + s[i + 1] - '0';

            if (val >= 10 && val <= 26) {
                dp[i] += ways(s, i + 2, dp);
            }
        }
        return dp[i];
    }
    int numDecodings(string s) {
        // vector<int> dp(s.size(), -1);
        // NOTE: This is memoization Solution
        // return ways(s, 0, dp);

        // NOTE: This is Tabulation Solution

        int n = s.size();
        vector<int> dp(n + 1, 0);

        dp[n] = 1;

        for (int i = n - 1; i >= 0; i--) {

            if (s[i] == '0') {
                dp[i] = 0;
                continue;
            }

            dp[i] = dp[i + 1];

            if (i + 1 < n) {
                int val = (s[i] - '0') * 10 + s[i + 1] - '0';

                if (val >= 10 && val <= 26)
                    dp[i] += dp[i + 2];
            }
        }
        return dp[0];
    }
};

int main() {
    string s = "10";
    Solution sol;

    cout << sol.numDecodings(s) << endl;
}
