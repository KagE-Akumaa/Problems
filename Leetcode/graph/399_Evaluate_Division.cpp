#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void giveMapping(unordered_map<string, int> &mpp,
                     vector<vector<string>> &equations) {
        int idx = 0;
        for (int i = 0; i < equations.size(); i++) {
            if (mpp.find(equations[i][0]) == mpp.end()) {
                mpp[equations[i][0]] = idx;
                idx++;
            }
            if (mpp.find(equations[i][1]) == mpp.end()) {
                mpp[equations[i][1]] = idx;
                idx++;
            }
        }
    }
    double bfs(int src, int dest, vector<vector<pair<int, double>>> &graph,
               int n) {
        vector<bool> visited(n, false);

        queue<pair<int, double>> q;
        q.push({src, 1.0});
        visited[src] = true;

        while (!q.empty()) {
            auto [node, val] = q.front();
            q.pop();

            if (node == dest) {
                return val;
            }

            for (auto [nb, w] : graph[node]) {
                if (!visited[nb]) {
                    visited[nb] = true;
                    q.push({nb, w * val});
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries) {

        unordered_map<string, int> mpp;

        giveMapping(mpp, equations);

        vector<vector<pair<int, double>>> graph(mpp.size());
        for (auto &it : mpp) {
            cout << it.first << " " << it.second << endl;
        }
        for (int i = 0; i < equations.size(); i++) {
            auto eq = equations[i];
            int u = mpp[eq[0]];
            int v = mpp[eq[1]];

            graph[u].push_back({v, values[i]});
            graph[v].push_back({u, 1.0 / values[i]});
        }
        // NOTE: Now we have made the graph with nodes now for each queries we
        // have to search a path from q[0] to q[1] and just multiply all the
        // weights to get the answer

        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            auto q = queries[i];

            if (mpp.find(q[0]) == mpp.end() || mpp.find(q[1]) == mpp.end()) {
                ans.push_back(-1.0);
                continue;
            }
            int src = mpp[q[0]];
            int dest = mpp[q[1]];

            // NOTE: Now we can do a bfs on this from source to destination and
            // return the result

            double result = bfs(src, dest, graph, mpp.size());

            ans.push_back(result);
        }
        return ans;
    }
};
