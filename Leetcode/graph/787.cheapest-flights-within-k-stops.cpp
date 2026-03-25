// @leet start
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    struct data {
        int d;
        int node;
        int stop;
    };
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
                          int k) {
        // code here
        vector<vector<pair<int, int>>> graph(n);

        for (auto &e : flights) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            graph[u].push_back({v, w});
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        dist[src][0] = 0;
        pq.push({0, src, 0});

        while (!pq.empty()) {
            auto [d, u, stop] = pq.top();
            pq.pop();

            if (d > dist[u][stop])
                continue;

            for (auto [v, w] : graph[u]) {
                if (stop + 1 <= k + 1 &&
                    dist[u][stop] + w < dist[v][stop + 1]) {
                    dist[v][stop + 1] = dist[u][stop] + w;
                    pq.push({dist[v][stop + 1], v, stop + 1});
                }
            }
        }

        int ans = INT_MAX;
        for (int s = 0; s <= k + 1; s++)
            ans = min(ans, dist[dst][s]);
        return ans == INT_MAX ? -1 : ans;
    }
};
// @leet end
