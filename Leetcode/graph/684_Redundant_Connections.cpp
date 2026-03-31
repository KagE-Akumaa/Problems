#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    struct Dsu {
        vector<int> parent, rnk;

        Dsu(int n) {
            parent.resize(n);
            rnk = vector<int>(n, 0);
            // Initialy every element is their own parent
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            // Returns the root of x set or the representative
            if (parent[x] == x) {
                return x;
            }
            return parent[x] = find(parent[x]);
        }
        void myUnion(int x, int y) {
            // Same as math union - take the set x and set y and merge them into
            // one
            int x1 = find(x);
            int y1 = find(y);

            if (x1 == y1) {
                // Already same set
                return;
            }
            if (rnk[x1] > rnk[y1]) {
                // x1 is larger so we add y1 as child
                parent[y1] = x1;
            } else if (rnk[y1] > rnk[x1]) {
                parent[x1] = y1;
            } else {
                // Both have same rnk
                parent[y1] = x1;
                rnk[x1]++;
            }
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        // We can use dsu and return the edge which can cause a cycle that means
        // if the parent of u and v are the same that means there is a cycle
        // between these two
        int n = edges.size();
        Dsu d(n + 1);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            int pu = d.find(u);
            int pv = d.find(v);

            if (pu == pv)
                return {u, v};
            d.myUnion(u, v);
        }

        return {-1, -1};
    }
};
