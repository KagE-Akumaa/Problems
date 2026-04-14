#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int bfs(int n, vector<vector<pair<int, int>>> &graph,
            vector<bool> &visited) {
        queue<int> q;
        q.push(n);
        visited[n] = true;

        int ans = INT_MAX;

        while (!q.empty()) {
            int node = q.front();
            visited[node] = true;
            q.pop();
            for (auto &[v, w] : graph[node]) {
                if (!visited[v]) {
                    q.push(v);
                }

                ans = min(w, ans);
            }
        }
        return ans;
    }
    int minScore(int n, vector<vector<int>> &roads) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        // NOTE: IF there always exists a valid path that means we just need to
        // find the minimum edge in that path
        vector<bool> visited(n + 1, false);

        queue<pair<int, int>> q;

        return bfs(1, graph, visited);
    }
};
