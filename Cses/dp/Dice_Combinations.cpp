#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
vector<int> nums{1, 2, 3, 4, 5, 6};
int findWays(int target, vector<int> &dp) {
        if (target == 0)
                return 1;
        if (target < 0)
                return 0;
        if (dp[target] != -1)
                return dp[target];
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
                ans = (ans + findWays(target - nums[i], dp)) % MOD;
        }
        return dp[target] = ans;
}
void solve() {
        int n;
        cin >> n;

        vector<int> dp(n + 1, -1);
        cout << findWays(n, dp) << endl;
}
int main() {
        int t = 1;

        while (t--) {
                solve();
        }
}
