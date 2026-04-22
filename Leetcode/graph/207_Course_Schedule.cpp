#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        //
        vector<vector<int>> graph(numCourses);

        vector<int> indegree(numCourses, 0);
        for (auto &it : prerequisites) {
            int u = it[1];
            int v = it[0];

            graph[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {

            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            auto node = q.front();
            q.pop();

            for (auto &nb : graph[node]) {
                indegree[nb]--;

                if (indegree[nb] == 0) {
                    q.push(nb);
                }
            }
        }

        for (auto &it : indegree) {
            if (it != 0)
                return false;
        }

        return true;
    }
};

int main() {
    vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};

    Solution s;

    cout << s.canFinish(2, prerequisites) << endl;
}
