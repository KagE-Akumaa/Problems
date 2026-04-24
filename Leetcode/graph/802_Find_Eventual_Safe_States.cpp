#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // OBSERVATION: Terminal node - no outdegree , safe node - all paths should
    // lead to Terminal node , if cycle exists then we can't reach the Terminal
    // node mark all neighbours of u to unsafe
    bool dfs(int node, vector<vector<int>> &graph, vector<bool> &visited,
             vector<bool> &inStack) {
        if (inStack[node])
            return true;
        if (visited[node])
            return false;
        visited[node] = true;
        inStack[node] = true;

        for (auto &nb : graph[node]) {
            if (dfs(nb, graph, visited, inStack)) {
                return true;
            }
        }
        inStack[node] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {

        vector<bool> visited(graph.size(), false), inStack(graph.size(), false);

        vector<int> ans;
        for (int i = 0; i < graph.size(); i++) {
            dfs(i, graph, visited, inStack);
        }

        for (int i = 0; i < graph.size(); i++) {
            if (!inStack[i])
                ans.push_back(i);
        }

        return ans;
    }
};
