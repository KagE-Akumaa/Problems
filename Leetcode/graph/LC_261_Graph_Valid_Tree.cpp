#include <bits/stdc++.h>
using namespace std;
struct Dsu {
    vector<int> parent, rnk;
    Dsu(int n) {
        parent.resize(n);
        rnk.assign(n, 0);

        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (x == parent[x])
            return x;

        return parent[x] = find(parent[x]);
    }

    void myDsu(int u, int v, int &count) {
        int x = find(u);
        int y = find(v);

        if (x == y)
            return;

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
bool validTree(int n, vector<vector<int>> &edges) {
    // NOTE: A graph is a valid tree only if it contains n - 1 edges and its
    // fully connected and no cycles
    //
    Dsu d(n);
    int count = n;
    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];

        if (d.find(u) == d.find(v)) {
            return false;
        }
        d.myDsu(u, v, count);
    }
    if (count == 1) {
        return true;
    }
    return false;
}
