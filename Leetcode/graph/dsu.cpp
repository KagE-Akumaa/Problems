#include <bits/stdc++.h>
using namespace std;

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
        // Same as math union - take the set x and set y and merge them into one
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
