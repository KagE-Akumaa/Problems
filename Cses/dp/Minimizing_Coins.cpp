#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int> &coins, int x, int i, vector<vector<int>> &dp) {
        if (x == 0)
                return 0;
        if (i == coins.size())
                return INT_MAX;
        if (dp[i][x] != -1)
                return dp[i][x];
        if (x >= coins[i]) {
                int take = minCoins(coins, x - coins[i], i, dp);
                if (take != INT_MAX)
                        take = take + 1;
                int not_take = minCoins(coins, x, i + 1, dp);

                return dp[i][x] = min(take, not_take);
        }

        return dp[i][x] = minCoins(coins, x, i + 1, dp);
}
void solve() {
        int n, x;
        cin >> n >> x;

        vector<int> coins(n);
        for (int &i : coins)
                cin >> i;

        // vector<vector<int>> dp(n, vector<int>(x + 1, -1));
        //
        // int val = minCoins(coins, x, 0, dp);
        // if (val == INT_MAX)
        //         cout << -1 << endl;
        // else
        //         cout << val << endl;

        vector<int> dp(x + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
                for (int c = 1; c < dp.size(); c++) {
                        if (c >= coins[i] && dp[c - coins[i]] != INT_MAX) {
                                dp[c] = min(1 + dp[c - coins[i]], dp[c]);
                        }
                }
        }
        cout << (dp[x] == INT_MAX ? -1 : dp[x]) << endl;
}

int main() {
        int t = 1;
        while (t--)
                solve();
}
