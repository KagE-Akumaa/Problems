// @leet start
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isBipartite(vector<vector<int>> &graph) {
        vector<int> color(graph.size(), -1);

        for (int i = 0; i < graph.size(); i++) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto &nb : graph[node]) {
                        // 2 cases either the nb is not colored or colored
                        if (color[nb] == -1) {
                            // Color opposite of that of parent
                            color[node] == 0 ? color[nb] = 1 : color[nb] = 0;
                            q.push(nb);
                        } else {
                            if (color[nb] == color[node])
                                return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};
// @leet end
