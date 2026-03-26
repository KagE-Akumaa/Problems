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

void helper(int node, int parent, vector<vector<int>> &graph, int &ans,
            int catCount, vector<int> &val, int m) {
    if (val[node] == 1) {
        catCount++;
    } else {
        catCount = 0;
    }
    if (catCount > m)
        return;
    if (node != 0 && graph[node].size() == 1) {
        ans++;
        return;
    }
    for (auto &nb : graph[node]) {
        if (nb != parent) {
            helper(nb, node, graph, ans, catCount, val, m);
        }
    }
}
void solver() {
    // write your code here
    int n, m;
    cin >> n >> m;

    vector<int> val(n, 0);
    for (int &i : val)
        cin >> i;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; i++) {
        int u;
        cin >> u;
        int v;
        cin >> v;
        graph[u - 1].push_back(v - 1);
        graph[v - 1].push_back(u - 1);
    }

    int ans = 0;
    // we need to count how many paths are there from root to leaf with < m
    // cats
    // USING DFS
    // int catCount = 0;
    // helper(0, -1, graph, ans, catCount, val, m);
    // cout << ans << endl;

    // NOTE: Using bfs
    queue<tuple<int, int, int>> q;
    q.push({0, -1, 0});

    while (!q.empty()) {
        auto [node, parent, consecutiveCat] = q.front();
        q.pop();

        // update the consecutiveCat count
        if (val[node] == 1) {
            consecutiveCat++;
        } else
            consecutiveCat = 0;
        // Check if count > m
        if (consecutiveCat > m) {
            continue;
        }
        // check if the node is leaf
        if (node != 0 && graph[node].size() == 1) {
            ans++;
            continue;
        }

        for (auto &nb : graph[node]) {
            if (nb != parent) {
                q.push({nb, node, consecutiveCat});
            }
        }
    }
    cout << ans << endl;
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
