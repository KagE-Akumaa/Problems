#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int maxDistance(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<tuple<int, int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j, 0});
                    visited[i][j] = true;
                }
            }
        }

        // NOTE: for 1 the distance is 0

        int mans = -1;
        while (!q.empty()) {
            auto [row, col, dist] = q.front();
            q.pop();

            mans = max(mans, dist);
            for (auto &it : dir) {
                int r = it.first + row, c = it.second + col;

                if (r >= 0 && r < m && c >= 0 && c < n && !visited[r][c]) {
                    int newDist = dist + 1;
                    q.push({r, c, newDist});
                    visited[r][c] = true;
                }
            }
        }
        return mans == 0 ? -1 : mans;
    }
};
