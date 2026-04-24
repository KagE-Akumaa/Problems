#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int node, vector<vector<int>> &graph, vector<vector<int>> &ans,
             vector<int> &temp, int dest, vector<bool> &visited) {
        //
        if (node == dest) {
            temp.push_back(dest);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }

        if (!visited[node] || node == 0) {
            visited[node] = true;
            temp.push_back(node);

            for (auto &nb : graph[node]) {
                dfs(nb, graph, ans, temp, dest, visited);
            }

            visited[node] = false;
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {

        int src = 0, dest = graph.size() - 1;

        vector<vector<int>> ans;
        vector<bool> visited(graph.size(), false);
        vector<int> temp;
        dfs(src, graph, ans, temp, dest, visited);
        return ans;
    }
};
