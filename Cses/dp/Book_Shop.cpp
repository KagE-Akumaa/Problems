#include <bits/stdc++.h>
using namespace std;

int maxPages(vector<int> &prices, vector<int> &pages, int x, int i) {
        if (i == prices.size() || x == 0)
                return 0;

        if (x >= prices[i]) {
                return max(pages[i] +
                               maxPages(prices, pages, x - prices[i], i + 1),
                           maxPages(prices, pages, x, i + 1));
        }
        return maxPages(prices, pages, x, i + 1);
}

int maxPages(vector<int> &prices, vector<int> &pages, int x, int i,
             vector<vector<int>> &dp) {
        if (i == prices.size() || x == 0)
                return 0;

        if (dp[i][x] != -1)
                return dp[i][x];
        if (x >= prices[i]) {
                return dp[i][x] = max(pages[i] + maxPages(prices, pages,
                                                          x - prices[i], i + 1),
                                      maxPages(prices, pages, x, i + 1));
        }
        return dp[i][x] = maxPages(prices, pages, x, i + 1);
}
void solve() {
        int n, x;
        cin >> n >> x;

        vector<int> prices(n), pages(n);

        for (int &i : prices) {
                cin >> i;
        }
        for (int &i : pages) {
                cin >> i;
        }
        // vector<vector<int>> dp(n, vector<int>(x + 1, -1));
        // NOTE: Normal recursive function Tc - O(2^n)
        // cout << maxPages(prices, pages, x, 0) << endl;
        // These all failed the input value is too big -> going to 1d dp
        // cout << maxPages(prices, pages, x, 0, dp) << endl;

        vector<int> dp(x + 1, 0);

        for (int i = 0; i < n; i++) {
                for (int w = dp.size() - 1; w >= 0; w--) {
                        if (w >= prices[i]) {
                                dp[w] =
                                    max(pages[i] + dp[w - prices[i]], dp[w]);
                        }
                }
        }

        cout << dp[x] << endl;
}
int main() {
        int t = 1;

        while (t--) {
                solve();
        }
}
