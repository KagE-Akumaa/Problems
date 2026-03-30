#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void dfs(int row, int col, vector<vector<int>> &grid, int m, int n) {
        grid[row][col] = 2;
        // For this row col we have to explore its neighbours and if its == 1
        // then we mark it How? we just call dfs on it and trust recursion to do
        // that :)

        for (auto &it : dir) {
            int r = it[0] + row, c = it[1] + col;

            // Bound check
            if (r < m && r >= 0 && c < n && c >= 0 && grid[r][c] == 1) {
                dfs(r, c, grid, m, n);
            }
        }
    }
    int numEnclaves(vector<vector<int>> &grid) {
        // 1 - Land, 0 - Water

        int m = grid.size(), n = grid[0].size();
#if 0

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 &&
                    (i == 0 || i == m - 1 || j == 0 || j == n - 1)) {
                    dfs(i, j, grid, m, n);
                }
            }
        }
        // Now after the dfs we should have a grid which will have the boundary
        // land marked as 2 so as their all neighbours So Now the only thing is
        // to count the land which are still at 1 as they cannot reach the
        // boundary unlucky :(

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) { // unlucky :(
                    count++;
                }
            }
        }
        return count;
#endif
        // NOTE: Now we do the same problem using a bfs ->
        //  What do we need for bfs? answer - a queue :)
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Now the condition if the value at row, col is 1 and its on
                // the boundary simple
                if (grid[i][j] == 1 &&
                    (i == 0 || i == m - 1 || j == 0 || j == n - 1)) {
                    q.push({i, j});
                    // We can mark these cells too as they are on the boundary
                    // so they are valid + we don't want to revisit them again
                    grid[i][j] = 2;
                }
            }
        }
        while (!q.empty()) {
            // Question: do we need to go level by level or simple can work ?
            // answer: simple will work because we just have to mark the cells
            // as reachable or not we don't need level we can use but not
            // necessary here
            auto [row, col] = q.front();
            q.pop();

            // Now same check the neighbours if they are 1 we push them into
            // queue if not then they are unlucky :(

            for (auto &it : dir) {
                int r = it[0] + row, c = col + it[1];

                // Bound check
                if (r < m && r >= 0 && c < n && c >= 0 && grid[r][c] == 1) {
                    // For bfs we need to mark them here only in dfs it was at
                    // the starting of function call it was taken care by
                    // recursion
                    grid[r][c] = 2;
                    q.push({r, c});
                }
            }
        }
        // Now same count the unlucky ones :(
        int count = 0;

        for (auto &arr : grid) {
            for (int &i : arr) {
                if (i == 1)
                    count++;
            }
        }
        return count;
    }
};
