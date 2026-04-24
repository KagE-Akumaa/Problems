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
    // OBSERVATION: Just count the connected components
    int findCircleNum(vector<vector<int>> &isConnected) {
        //
        int m = isConnected.size(), n = isConnected[0].size();
#if 0
        // NOTE: This is using dfs
        
        vector<vector<int>> graph(m);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        vector<bool> visited(m, false);

        auto dfs = [&](auto &self, int node) -> void {
            visited[node] = true;

            for (auto &nb : graph[node]) {
                if (!visited[nb]) {
                    self(self, nb);
                }
            }
        };
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(dfs, i);
                count++;
            }
        }
        return count;
#endif
        Dsu d(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    d.myUnion(i, j);
                }
            }
        }
        unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            st.insert(d.find(i));
        }

        return st.size();
    }
};
