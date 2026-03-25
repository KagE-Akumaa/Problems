// @leet start
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {

        vector<vector<pair<int, int>>> graph(n + 1);

        vector<int> dist(n + 1, INT_MAX);

        for (auto &e : times) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            graph[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto [v, w] : graph[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(dist[i], ans);
        }
        return ans;
    }
};
// @leet end
