#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int src, int dest, vector<vector<int>> &graph, int n) {
    queue<int> q;
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    q.push(src);

    visited[src] = true;

    int count = 1;
    while (!q.empty()) {
        int lvl = q.size();

        while (lvl--) {
            auto node = q.front();
            q.pop();
            if (node == dest) {
                return parent;
            }

            for (auto &nb : graph[node]) {
                if (!visited[nb]) {
                    q.push(nb);
                    visited[nb] = true;
                    parent[nb] = node;
                }
            }
        }
        count++;
    }
    return parent;
}
void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // OBSERVATION: We can find the minimum computers by using bfs the problem
    // is with getting the edges - problem solved we need to make a parent array
    // to track from where we came then we need to reconstruct the path curr =
    // dest then loop until we find the node for which there is no parent.

    int src = 1, dest = n;

    vector<int> val = bfs(src, dest, graph, n + 1);

    if (val[dest] == -1) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    vector<int> path;

    int cur = dest;
    while (cur != -1) {
        path.push_back(cur);
        cur = val[cur];
    }

    reverse(path.begin(), path.end());
    cout << path.size() << endl;
    for (auto &node : path) {
        cout << node << " ";
    }
    cout << endl;
}
int main() {
    int t = 1;
    while (t--) {
        solve();
    }
}
