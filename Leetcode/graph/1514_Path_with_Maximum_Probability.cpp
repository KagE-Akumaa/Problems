#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double maxProbability(int n, vector<vector<int>> &edges,
                          vector<double> &succProb, int start_node,
                          int end_node) {
        vector<vector<pair<double, double>>> graph(n);

        int i = 0;
        for (auto &it : edges) {
            double u = it[0];
            double v = it[1];
            double w = succProb[i];
            i++;

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        vector<double> dist(n, 0.0);

        dist[start_node] = 1.0;

        priority_queue<pair<double, double>, vector<pair<double, double>>> pq;

        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d < dist[u])
                continue;

            for (auto &[v, w] : graph[u]) {
                if (dist[v] < dist[u] * w) {
                    dist[v] = dist[u] * w;

                    pq.push({dist[v], v});
                }
            }
        }

        return dist[end_node];
    }
};
