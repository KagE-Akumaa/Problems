#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // OBSERVATION: Just count the connected components
    int findCircleNum(vector<vector<int>> &isConnected) {
        //
        int m = isConnected.size(), n = isConnected[0].size();
        vector<vector<int>> graph(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        vector<bool> visited(m, false);

        auto dfs = [&](auto &self, int node) -> void {
            visited[node] = true;

            for (auto &nb : graph[node]) {
                if (!visited[nb]) {
                    self(self, nb);
                }
            }
        };
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(dfs, i);
                count++;
            }
        }
        return count;
    }
};
