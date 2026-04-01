#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    struct Dsu {
        vector<int> parent, rnk;

        Dsu(int n) {
            parent.resize(n);
            rnk = vector<int>(n, 0);

            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        int find(int x) {
            if (parent[x] == x)
                return x;
            return parent[x] = find(parent[x]);
        }
        void myUnion(int x, int y) {
            int x1 = find(x);
            int y1 = find(y);

            if (x1 == y1) {
                return;
            }
            if (rnk[x1] > rnk[y1]) {
                parent[y1] = x1;
            } else if (rnk[y1] > rnk[x1]) {
                parent[x1] = y1;
            } else {

                parent[y1] = x1;
                rnk[x1]++;
            }
        }
    };
    bool bfs(int src, int dest, vector<vector<int>> &graph, int V) {
        vector<bool> visited(V, false);

        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == dest)
                return true;
            for (auto &nb : graph[node]) {
                if (!visited[nb]) {
                    visited[nb] = true;
                    q.push(nb);
                }
            }
        }
        return false;
    }

    bool dfs(int src, int dest, vector<vector<int>> &graph,
             vector<bool> &visited) {
        //
        visited[src] = true;
        if (src == dest)
            return true;

        for (auto &nb : graph[src]) {
            if (!visited[nb]) {
                if (dfs(nb, dest, graph, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool equationsPossible(vector<string> &equations) {
        // NOTE: Dsu is better for this problem because the time complexity will
        // be around O(n) as the vector size is only 26 and the string size is
        // also just 4 But for bfs/dfs the time complexity will be O(n^2) as
        // first we need to build the graph and then for every != we have to do
        // a bfs/dfs which will take O(v+e) time and for n it will take O(n *
        // (v+e)) and e can be upto n so O(n * (n + v)) which is equal to O(n^2)
        Dsu d(26);

        // NOTE: Why do we do it in 2 passes? because first we need to group the
        // sets which contains "==" and then we need to check if the element
        // belongs to "!=" then if it exists in "==" set that means
        // contradiction and we can just return false
#if 0
        for (auto &eq : equations) {
            int u = eq[0] - 'a', v = eq[3] - 'a';
            string op;
            op.push_back(eq[1]);
            op.push_back(eq[2]);

            if (op == "==") {
                // We do union of u and v
                d.myUnion(u, v);
            }
        }
        for (auto &eq : equations) {
            int u = eq[0] - 'a', v = eq[3] - 'a';
            string op;
            op.push_back(eq[1]);
            op.push_back(eq[2]);

            if (op == "!=") {
                // We check if the belong the to the same set that means the
                // operation is not possible
                if (d.find(u) == d.find(v)) {
                    return false;
                }
            }
        }
        return true;
#endif
        // NOTE: Solving this problem with bfs/dfs to improve traversals :)

#if 0
        // Step - 1 is to create a graph from u to v which contains "=="
        vector<vector<int>> graph(26);

        for (auto &eq : equations) {
            int u = eq[0] - 'a', v = eq[3] - 'a';
            string op;
            op.push_back(eq[1]);
            op.push_back(eq[2]);

            if (op == "==") {
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
        // Step -2 for every != do a dfs/bfs from u to v if its possible to
        // reach from u to v that means its contradiction then we return false

        for (auto &eq : equations) {
            int u = eq[0] - 'a', v = eq[3] - 'a';
            string op;
            op.push_back(eq[1]);
            op.push_back(eq[2]);

            if (op == "!=") {
                if (bfs(u, v, graph, 26)) {
                    // Means can we reach from u to v?
                    // if yes return false
                    return false;
                }
            }
        }
        return true;
#endif
        // NOTE: Now Solving Using dfs :)

        vector<vector<int>> graph(26);
        for (auto &eq : equations) {
            int u = eq[0] - 'a', v = eq[3] - 'a';
            string op;
            op.push_back(eq[1]);
            op.push_back(eq[2]);

            if (op == "==") {
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        }
        // Step -2 for every != do a dfs/bfs from u to v if its possible to
        // reach from u to v that means its contradiction then we return false

        for (auto &eq : equations) {
            int u = eq[0] - 'a', v = eq[3] - 'a';
            string op;
            op.push_back(eq[1]);
            op.push_back(eq[2]);

            if (op == "!=") {
                vector<bool> visited(26, false);
                if (dfs(u, v, graph, visited)) {
                    // Means can we reach from u to v?
                    // if yes return false
                    return false;
                }
            }
        }
        return true;
    }
};
