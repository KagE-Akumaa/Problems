#include <bits/stdc++.h>
#define int long long
using namespace std;

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
/*
 Observations




 */

void solver() {
    // write your code here
    int n;
    cin >> n;
    vector<int> edges(n + 1);

    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        edges[i] = val;
    }

    for (int i = 1; i <= n; i++) {
        if (edges[edges[edges[i]]] == i) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //    cin >> t; // comment if only one test case
    while (t--)
        solver();
    return 0;
}
