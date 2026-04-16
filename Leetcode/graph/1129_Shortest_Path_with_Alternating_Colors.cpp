#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int bfs(vector<vector<pair<int, int>>> &graph, int src, int dest) {
        vector<vector<bool>> visited(graph.size(), vector<bool>(2, false));
        queue<pair<int, int>> q;
        q.push({src, 0});
        q.push({src, 1});
        visited[0][0] = true;
        visited[0][1] = true;
        int d = 0;
        while (!q.empty()) {
            int lvl = q.size();
            while (lvl--) {
                auto [node, color] = q.front();
                q.pop();

                if (node == dest) {
                    return d;
                }
                for (auto &[v, c] : graph[node]) {
                    if (!visited[v][c] && c != color) {
                        q.push({v, c});
                        visited[v][c] = true;
                    }
                }
            }
            d++;
        }
        return -1;
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges,
                                         vector<vector<int>> &blueEdges) {
        vector<vector<pair<int, int>>> graph(n);

        for (auto &it : redEdges) {
            int u = it[0];
            int v = it[1];

            graph[u].push_back({v, 0});
        }

        for (auto &it : blueEdges) {
            int u = it[0];
            int v = it[1];

            graph[u].push_back({v, 1});
        }

        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            int d = bfs(graph, 0, i);
            ans[i] = d;
        }
        return ans;
    }
};
