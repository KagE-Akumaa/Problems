#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
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
    vector<vector<int>>
    findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {
        // Build a graph from this then generate all the mst -> pick the common
        // edges as critical and other as pseudo
        // This might be a naive way to solve the problem

        vector<vector<pair<int, int>>> graph(n);

        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        // Sort the graph according to the minimum weight

        sort(graph.begin(), graph.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 return a[2] < b[2];
             });

        // We have a choice to pick any node but if we add sorting our choice
        // will ditrubed we need to pick a random node and then try to greedily
        // choose the lowest weight - Prim's algorithm

        //QUES: What if we choose ith node and then do the greedy searching using Krushkal's algorithm

        for (int i = 0; i < n; i++) {
            
        }
    }
};
