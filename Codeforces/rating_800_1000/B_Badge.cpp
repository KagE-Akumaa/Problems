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

struct Dsu {
    vector<int> parent, rnk;
    Dsu(int n) {
        parent.resize(n);
        rnk.assign(n, 0);

        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void myUnion(int u, int v) {
        int x = find(u);
        int y = find(v);

        if (x == y)
            return;
        if (rnk[x] > rnk[y]) {
            parent[y] = x;
        } else if (rnk[y] > rnk[x]) {
            parent[x] = y;
        } else {
            parent[y] = x;
            rnk[x]++;
        }
    }
};
void solver() {
    // write your code here
    int n;
    cin >> n;
    vector<int> res(n + 1, 0);

    for (int i = 1; i < n + 1; i++) {
        int v;
        cin >> v;
        res[i] = v;
    }
    for (int i = 1; i < n + 1; i++) {
        int a = i;
        vector<bool> visited(n + 1, false);

        int current = a;
        visited[current] = true;
        while (true) {
            current = res[current];
            if (visited[current]) {
                cout << current << " ";
                break;
            }
            visited[current] = true;
        }
    }
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
