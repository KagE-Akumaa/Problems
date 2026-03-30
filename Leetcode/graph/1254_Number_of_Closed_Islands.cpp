#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool bfs(int row, int col, vector<vector<int>> &grid, int m, int n) {
        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = 1;

        bool isClosed = true;
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            // If the condition fails we mark isClosed as false and now we will
            // explore the whole island so that for that whole connected island
            // we can say collectively that this is not a closed island
            if (row == 0 || row == m - 1 || col == 0 || col == n - 1) {
                isClosed = false;
            }
            for (auto &it : dir) {
                int r = it.first + row, c = it.second + col;
                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 0) {
                    // If this cell is surrounded by water then we add this into
                    // the queue else for this direction we won't add it but
                    // still mark it as visited
                    grid[r][c] = 1;
                    q.push({r, c});
                }
            }
        }
        return isClosed;
    }
    int closedIsland(vector<vector<int>> &grid) {

        // Land - 0 and Water - 1
        int m = grid.size(), n = grid[0].size();

        // Variable for counting closedIsland
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // The condition is it should be an island and it should
                // not be on the boundary as then how will it be
                // surrounded by water?
                if (grid[i][j] == 0 &&
                    (i != 0 && i != m - 1 && j != 0 && j != n - 1)) {
                    if (bfs(i, j, grid, m, n)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
