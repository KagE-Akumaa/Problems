#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    double maxProbability(int n, vector<vector<int>> &edges,
                          vector<double> &succProb, int start_node,
                          int end_node) {
        vector<vector<pair<int, int>>> graph(n);

        int i = 0;
        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int w = succProb[i];
            i++;

            graph[u].push_back({v, w});
        }
    }
};
