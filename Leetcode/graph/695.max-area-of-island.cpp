// @leet start
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Better to make it global instead writing inside the recursive function
    vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    void dfs(int row, int col, vector<vector<int>> &grid,
             vector<vector<bool>> &visited, int m, int n, int &area) {
        //
        if (!visited[row][col] && grid[row][col] == 1) {
            visited[row][col] = true;
            // Area is counted for every dfs call
            area++;

            // Need to check 4 directions l d u r
            for (auto &it : dir) {
                int r = row + it.first, c = col + it.second;

                // Bound checking
                if (r >= 0 && r < m && c >= 0 && c < n) {
                    dfs(r, c, grid, visited, m, n, area);
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        vector<vector<bool>> visited(grid.size(),
                                     vector<bool>(grid[0].size(), false));

        int marea = 0;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    int area = 0;
                    dfs(i, j, grid, visited, m, n, area);

                    marea = max(marea, area);
                }
            }
        }
        return marea;
    }
};
// @leet end
