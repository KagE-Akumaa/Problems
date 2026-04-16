// @leet start
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int bfs(queue<pair<int, int>> &q, vector<vector<int>> &grid, int m, int n) {
        int min = 0;

        while (!q.empty()) {
            int lvl = q.size();
            while (lvl--) {
                auto [row, col] = q.front();
                q.pop();

                // NOTE: now check the 4 directions
                for (auto &it : dir) {
                    int r = it.first + row, c = it.second + col;

                    if (r >= 0 && r < m && c < n && c >= 0 && grid[r][c] == 1) {
                        q.push({r, c});
                        grid[r][c] = 2;
                    }
                }
            }
            if (q.size() > 0) {
                min++;
            }
        }
        return min;
    }
    int orangesRotting(vector<vector<int>> &grid) {
        // NOTE: Rotted oranges are 2 we can push all those to queue and start a
        // bfs and count level by level on how many minutes it take to
        // completely rott every orange - if any orange is not rotted we return
        // -1

        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int minutes = bfs(q, grid, m, n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return minutes;
    }
};
