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
        void myUnion(int u, int v) {
            int x = find(u);
            int y = find(v);

            if (x == y) {
                return;
            }

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
    void print(vector<vector<int>> &grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
    int removeStones(vector<vector<int>> &stones) {

        int count = 0;

        Dsu d(stones.size());
        int n = 2;
        auto check = [&](int r, int c, int idx) {
            for (int i = idx + 1; i < stones.size(); i++) {
                int cr = stones[i][0];
                int cc = stones[i][1];

                if (cr == r || cc == c) {
                    d.myUnion(idx, i);
                }
            }
        };
        for (int i = 0; i < stones.size(); i++) {
            int r = stones[i][0];
            int c = stones[i][1];

            check(r, c, i);
        }
        // now count the unique parents
        unordered_set<int> st;
        for (int i = 0; i < stones.size(); i++) {
            st.insert(d.find(i));
        }
        return stones.size() - st.size();
    }
};
