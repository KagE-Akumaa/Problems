// @leet start
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int orangesRotting(vector<vector<int>> &grid) {

        queue<pair<int, int>> q;

        // Find the oranges which are already rotting

        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        int count = 0;

        while (!q.empty()) {
            int lvl = q.size();

            for (int i = 0; i < lvl; i++) {

                auto [row, col] = q.front();
                q.pop();

                // Need to check 4 directions
                if (col - 1 >= 0 && grid[row][col - 1] == 1) {
                    grid[row][col - 1] = 2;
                    q.push({row, col - 1});
                }
                if (col + 1 < n && grid[row][col + 1] == 1) {
                    grid[row][col + 1] = 2;
                    q.push({row, col + 1});
                }

                if (row - 1 >= 0 && grid[row - 1][col] == 1) {
                    grid[row - 1][col] = 2;
                    q.push({row - 1, col});
                }
                if (row + 1 < m && grid[row + 1][col] == 1) {
                    grid[row + 1][col] = 2;
                    q.push({row + 1, col});
                }
            }

            if (q.size() > 0) {
                count++;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)

                    return -1;
            }
        }
        return count;
    }
};
// @leet end
