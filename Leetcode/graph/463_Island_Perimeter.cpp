#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(int row, int col, vector<vector<int>> &grid,
             vector<vector<bool>> &visited, int &perimeter, int m, int n) {
        if (!visited[row][col] && grid[row][col] == 1) {
            visited[row][col] = true;

            for (auto &it : dir) {
                int r = it.first + row, c = it.second + col;

                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
                    // NOTE: This means this is an island -> we do dfs on this
                    dfs(r, c, grid, visited, perimeter, m, n);
                } else {
                    perimeter++;
                }
            }
        }
    }
    int islandPerimeter(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int perimeter = 0;

        // QUES: How do we get the perimeter in this?
        // ANS: We can think like this if the four direction of an island - is
        // surrounded by water that means the perimeter is 4 one for each side
        // so we just want to calculate the sides which as completely surrounded
        // by water and add + 1 to our perimeter:)

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    dfs(i, j, grid, visited, perimeter, m, n);
                }
            }
        }
        return perimeter;
    }
};
