#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int numEnclaves(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();

        // Push  1 which are at the boundary
        queue<pair<int, int>> q;
        for (int row = 0; row < m; row++) {
            if (grid[row][0] == 1) {
                grid[row][0] = 2;
                q.push({row, 0});
            }
            if (grid[row][n - 1] == 1) {
                grid[row][n - 1] = 2;
                q.push({row, n - 1});
            }
        }
        for (int col = 0; col < n; col++) {
            if (grid[0][col] == 1) {
                grid[0][col] = 2;
                q.push({0, col});
            }
            if (grid[m - 1][col] == 1) {
                grid[m - 1][col] = 2;
                q.push({m - 1, col});
            }
        }
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (auto &it : dir) {
                int r = it.first + row, c = it.second + col;

                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
                    grid[r][c] = 2;
                    q.push({r, c});
                }
            }
        }
        int count = 0;

        for (auto &it : grid) {
            for (auto &i : it) {
                if (i == 1)
                    count++;
            }
        }
        return count;
    }
};
