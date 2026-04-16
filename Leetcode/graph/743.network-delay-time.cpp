// @leet start
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);

        for (auto &it : times) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            graph[u].push_back({v, w});
        }

        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto &[v, w] : graph[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = 0;

        for (int i = 1; i < dist.size(); i++) {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
// @leet end
