#include <bits/stdc++.h>
#define int long long
using namespace std;
/*--------------------- Prefix Sum 1D ---------------------*/
void gen_prefix_1D(vector<int> &pre, const vector<int> &v) {
        int n = v.size();
        pre[0] = v[0];
        for (int i = 1; i < n; i++) {
                pre[i] = pre[i - 1] + v[i];
        }
}
int prefix_solver_1D(const vector<int> &pre, int l, int r) {
        if (l == 0)
                return pre[r];
        return pre[r] - pre[l - 1];
}

/*--------------------- Prefix Sum 2D ---------------------*/
void gen_prefix_2D(vector<vector<int>> &pre, const vector<vector<int>> &v) {
        int n = v.size(), m = v[0].size();
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                        pre[i][j] = v[i][j];
                        if (i > 0)
                                pre[i][j] += pre[i - 1][j];
                        if (j > 0)
                                pre[i][j] += pre[i][j - 1];
                        if (i > 0 and j > 0)
                                pre[i][j] -= pre[i - 1][j - 1];
                }
        }
}
int prefix_solver_2D(const vector<vector<int>> &pre, int l1, int r1, int l2,
                     int r2) {
        int ans = pre[l2][r2];
        if (l1 > 0)
                ans -= pre[l1 - 1][r2];
        if (r1 > 0)
                ans -= pre[l2][r1 - 1];
        if (l1 > 0 && r1 > 0)
                ans += pre[l1 - 1][r1 - 1];
        return ans;
}
/*
 Observations




 */

int knapsack(vector<int> &weight, vector<int> &value, int total_weight, int i,
             vector<vector<int>> &dp) {
        if (total_weight == 0) {
                return 0;
        }
        if (i >= weight.size()) {
                return 0;
        }

        if (total_weight >= weight[i]) {
                int take =
                    value[i] + knapsack(weight, value, total_weight - weight[i],
                                        i + 1, dp);

                int not_take = knapsack(weight, value, total_weight, i + 1, dp);

                return dp[i][total_weight] = max(take, not_take);
        }

        return dp[i][total_weight] =
                   knapsack(weight, value, total_weight, i + 1, dp);
}
void solver() {
        // write your code here

        int n, w;

        cin >> n >> w;

        vector<int> weight(n), value(n);

        for (int i = 0; i < n; i++) {
                int x, y;

                cin >> x >> y;

                weight[i] = x;
                value[i] = y;
        }

#if 0
        // NOTE: MEMOIZED VERSION RESULTS TO TLE

        vector<vector<int>> dp(n, vector<int>(w + 1, -1));

        cout << knapsack(weight, value, w, 0, dp);
#endif
#if 0
        vector<vector<int>> dp(n, vector<int>(w + 1, 0));

        for (int t = 0; t <= w; t++) {
                if (t >= weight[0]) {
                        dp[0][t] = value[0];
                }
        }

        dp[0][0] = 0;
        for (int i = 1; i < n; i++) {
                for (int t = 1; t <= w; t++) {

                        if (t >= weight[i]) {

                                dp[i][t] =
                                    max(value[i] + dp[i - 1][t - weight[i]],

                                        dp[i - 1][t]);
                        } else {
                                dp[i][t] = dp[i - 1][t];
                        }
                }
        }

        cout << dp[n - 1][w] << endl;
#endif
        vector<int> dp(w + 1, 0);

        for (int i = 0; i < n; i++) {
                for (int t = dp.size() - 1; t >= 0; t--) {
                        if (t >= weight[i]) {
                                dp[t] =
                                    max(value[i] + dp[t - weight[i]], dp[t]);
                        }
                }
        }
        cout << dp[w] << endl;
}
int32_t main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int t = 1;
        // cin >> t; // comment if only one test case
        while (t--)
                solver();
        return 0;
}
