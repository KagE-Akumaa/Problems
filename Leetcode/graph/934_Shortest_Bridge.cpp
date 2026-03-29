#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    void dfs(int row, int col, vector<vector<bool>> &visited,
             vector<vector<int>> &grid, int m, int n) {
        if (!visited[row][col] && grid[row][col] == 1) {
            visited[row][col] = true;

            for (auto &it : dir) {
                int r = it.first + row, c = it.second + col;

                if (r >= 0 && r < m && c >= 0 && c < n && !visited[r][c] &&
                    grid[r][c] == 1) {
                    dfs(r, c, visited, grid, m, n);
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    // Find all the island for this and make a big island out of
                    // this
                    dfs(i, j, visited, grid, m, n);
                    goto done;
                }
            }
        }
    done:
        // NOTE: Now the second phase we added all island which connects from
        // the first island now we have to find the path from first to second
        // island
        queue<pair<int, int>> q;
        // NOTE: This will become the multisource bfs we add all the
        // visited[row][col] to the queue

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j]) {
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

                for (auto &it : dir) {
                    int r = it.first + row, c = it.second + col;

                    if (r >= 0 && r < m && c < n && c >= 0 && !visited[r][c]) {
                        if (grid[r][c] == 1)
                            return count;
                        visited[r][c] = true;
                        q.push({r, c});
                    }
                }
            }
            count++;
        }
        return count;
    }
};
