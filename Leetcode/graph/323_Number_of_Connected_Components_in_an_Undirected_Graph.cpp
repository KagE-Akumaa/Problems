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
            if (x == parent[x]) {
                return x;
            }
            return parent[x] = find(parent[x]);
        }
        void myUnion(int u, int v, int &count) {
            int x = find(u);
            int y = find(v);

            if (x == y) {

                return;
            }

            if (rnk[x] > rnk[y]) {
                parent[y] = x;
                count--;

            } else if (rnk[y] > rnk[x]) {
                parent[x] = y;
                count--;
            } else {
                parent[y] = x;
                rnk[x]++;
                count--;
            }
        }
    };
    void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited) {
        visited[node] = true;

        for (auto &nb : graph[node]) {
            if (!visited[nb]) {
                dfs(nb, graph, visited);
            }
        }
    }
    void bfs(int node, vector<vector<int>> &graph, vector<bool> &visited) {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            for (auto &nb : graph[curr]) {
                if (!visited[nb]) {
                    q.push(nb);
                    visited[nb] = true;
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>> &edges) {

        int count = n;

        // vector<vector<int>> graph(n);
        // for (auto &e : edges) {
        //     int u = e[0];
        //     int v = e[1];
        //
        //     graph[u].push_back(v);
        //     graph[v].push_back(u);
        // }
        // NOTE: This is using dfs and bfs
        //  vector<bool> visited(n, false);
        //  for (int i = 0; i < n; i++) {
        //      if (!visited[i]) {
        //          // dfs(i, graph, visited);
        //          bfs(i, graph, visited);
        //          count++;
        //      }
        //  }

        // NOTE: This is using Dsu for starting each and every component is
        // connected to itself so the count is = n when we Union some u and v
        // and there parents are not same in that case it means we are merging
        // them to 1 so that must means they are connected to each other so
        // count goes of by - count--
        Dsu d(n);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            d.myUnion(u, v, count);
        }
        // unordered_set<int> st;
        //
        // for (int i = 0; i < n; i++) {
        //     st.insert(d.find(i));
        // }
        return count;
    }
};

int main() {
    Solution s;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};
    int n = 5;

    cout << s.countComponents(n, edges) << endl;
}
