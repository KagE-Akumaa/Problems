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
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int removeStones(vector<vector<int>> &stones) {
        //
        int n = stones.size();
        Dsu d(n * n);

        vector<vector<int>> grid(n, vector<int>(n, 0));

        for (auto &e : stones) {
            grid[e[0]][e[1]] = 1;
        }

        vector<pair<int, int>> rem;
        print(grid);
        int count = 0;
        auto check = [&](int row, int col) -> bool {
            for (auto &it : dir) {
                int r = it.first + row, c = it.second + col;

                if (r >= 0 && r < n && c >= 0 && c < n && grid[r][c] == 1) {
                    return true;
                }
            }
            return false;
        };
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    // We need to check its four direction if that contains a
                    // stone that means we can delete this so we union it with
                    // the position of the new stone

                    if (check(i, j)) {
                        count++;
                        // Change the stone
                        rem.push_back({i, j});
                    }
                }
            }
        }
        for (auto &it : rem) {
            grid[it.first][it.second] = 0;
        }
        print(grid);
        return count;
    }
};
