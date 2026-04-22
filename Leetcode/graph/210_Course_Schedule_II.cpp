
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for (auto &it : prerequisites) {

            int u = it[1];
            int v = it[0];

            indegree[v]++;

            graph[u].push_back(v);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            ans.push_back(node);
            for (auto &nb : graph[node]) {

                indegree[nb]--;
                if (indegree[nb] == 0) {
                    q.push(nb);
                }
            }
        }

        if (ans.size() != numCourses)
            return {};

        return ans;
    }
};
