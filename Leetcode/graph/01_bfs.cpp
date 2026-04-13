#include <bits/stdc++.h>
using namespace std;

/* You have an undirected graph with n nodes and edges that each have a weight
of either 0 or 1. Given a source node src, find the shortest distance from src
to all other nodes. Input format: n = 5, src = 0 edges = [(0,1,0), (0,2,1),
(1,3,0), (2,3,1), (3,4,1)]
// (u, v, w)
Expected output:
dist = [0, 0, 1, 0, 1]*/
vector<int> zeroOneBFS(int n, int src, vector<tuple<int, int, int>> &edges) {
    // your code
    vector<vector<pair<int, int>>> graph(n);

    for (auto &it : edges) {
        auto [u, v, w] = it;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<int> dist(n, INT_MAX);

    dist[src] = 0;
    deque<int> dq;
    dq.push_back(src);

    while (!dq.empty()) {
        int node = dq.front();
        dq.pop_front();

        for (auto &[v, w] : graph[node]) {

            if (dist[v] > dist[node] + w) {
                dist[v] = dist[node] + w;
                if (w == 0) {
                    dq.push_front(v);
                } else {
                    dq.push_back(v);
                }
            }
        }
    }
    return dist;
}

int main() {
    vector<tuple<int, int, int>> edges = {
        {0, 1, 0}, {0, 2, 1}, {1, 3, 0}, {2, 3, 1}, {3, 4, 1}};

    int n = 5;
    vector<int> ans = zeroOneBFS(n, 0, edges);

    for (auto &it : ans) {
        cout << it << " ";
    }
    cout << endl;
}
