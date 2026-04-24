#include <bits/stdc++.h>
using namespace std;

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
void solve() {
    int n, m;
    cin >> n >> m;

#if 0
    // NOTE: This is using dfs - Count the connected componets k - 1 is the
    // answer and printing the edges
    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int count = 0;
    vector<int> ans;
    vector<bool> visited(n + 1, false);

    auto dfs = [&](auto &self, int node) -> void {
        visited[node] = true;

        for (auto &nb : graph[node]) {
            if (!visited[nb])
                self(self, nb);
        }
    };

    for (int i = 1; i < n + 1; i++) {
        if (!visited[i]) {
            dfs(dfs, i);
            ans.push_back(i);
            count++;
        }
    }
    cout << count - 1 << endl;
    if (count - 1 == 0)
        return;
    for (int i = 1; i < ans.size(); i++) {
        cout << ans[i - 1] << " " << ans[i] << endl;
    }
    cout << endl;
#endif
    Dsu d(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        d.myUnion(u, v);
    }

    vector<int> ans;

    for (int i = 1; i < n + 1; i++) {
        if (d.find(i) == i) {
            ans.push_back(i);
        }
    }

    cout << ans.size() -1 << endl;

    for (int i = 1; i < ans.size(); i++) {
        cout << ans[i -1] << " " << ans[i] << endl;
    }
}

int main() {
    int t = 1;

    while (t--)
        solve();
}
