#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        if (n == 1) {
            return cost[0];
        }
        if (n == 2) {
            return min(cost[0], cost[1]);
        }

        vector<int> dp(n, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        int a = cost[0];
        int b = cost[1];
        int c = 0;
        for (int i = 2; i < n; i++) {
            c = cost[i] + min(a, b);

            a = b;
            b = c;
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        return min(a, b);
    }
};

int main() {
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    Solution s;
    cout << s.minCostClimbingStairs(cost) << endl;
}
