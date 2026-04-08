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

    bool equationsPossible(vector<string> &equations) {
        Dsu d(26);

        for (int i = 0; i < equations.size(); i++) {
            auto it = equations[i];
            int u = it[0] - 'a';
            int v = it[3] - 'a';

            if (it[1] == '=') {
                d.myUnion(u, v);
            } else if (it[1] == '!') {
                if (d.find(u) == d.find(v))
                    return false;
            }
        }
        return true;
    }
};
