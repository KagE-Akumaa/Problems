#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool dfs(int row, int col, vector<vector<bool>> &visited,
             vector<vector<int>> &grid, int m, int n) {

        visited[row][col] = true;

        bool result = true;

        if (row == 0 || row == m - 1 || col == 0 || col == n - 1) {
            result = false;
        }

        for (auto &it : dir) {
            int r = row + it.first, c = col + it.second;

            if (r >= 0 && r < m && c >= 0 && c < n && !visited[r][c] &&
                grid[r][c] == 0) {

                result &= dfs(r, c, visited, grid, m, n);
            }
        }

        return result;
    }
    int closedIsland(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 0) {
                    if (dfs(i, j, visited, grid, m, n)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
