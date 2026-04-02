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
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int numIslands(vector<vector<char>> &grid) {
        int m = grid.size(), n = grid[0].size();
        Dsu d(m * n);

        auto check = [&](int row, int col) -> void {
            for (auto &it : dir) {
                int r = it.first + row, c = it.second + col;
                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                    d.myUnion(row * n + col, r * n + c);
                }
            }
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // NOTE: Now we have to find an island which is = 1 after
                // that we need to explore it's neighbours if they are aslo
                // land we union them into one set

                if (grid[i][j] == '1') {
                    // NOTE: if neighbours are land union them that means we
                    // have to union the current row, col with the
                    // neighbours row, col
                    check(i, j);
                }
            }
        }
        unordered_set<int> st;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    st.insert(d.find(i * n + j));
                }
            }
        }
        return st.size();
    }
};
