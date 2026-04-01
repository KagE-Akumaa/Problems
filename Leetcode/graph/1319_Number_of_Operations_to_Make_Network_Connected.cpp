#include <bits/stdc++.h>
using namespace std;
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

        if (x1 == y1)
            return;
        if (rnk[x1] > rnk[y1]) {
            parent[y1] = x1;
        } else if (rnk[y1] > rnk[x1]) {
            parent[x1] = y1;
        }

        else {
            parent[y1] = x1;
            rnk[x1]++;
        }
    }
};
class Solution {
  public:
    int makeConnected(int n, vector<vector<int>> &connections) {
        if (connections.size() < n - 1)
            return -1;
        Dsu d(n);
        for (auto &it : connections) {
            int u = it[0], v = it[1];
            d.myUnion(u, v);
        }
        unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            st.insert(d.find(i));
        }
        return st.size() - 1;
    }
};
