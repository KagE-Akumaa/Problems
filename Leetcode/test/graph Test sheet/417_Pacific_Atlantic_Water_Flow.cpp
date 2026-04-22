#include <bits/stdc++.h>
using namespace std;

// OBSERVATION: For every cell we can check if water can flow to both the
// oceans. We can make a separate array for atlantic and pacific ocean and then
// we can get the common elements that would be the answer. pacific - top and
// left, atlantic - bottom and right

class Solution {
  public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void bfs(queue<pair<int, int>> &q, vector<vector<int>> &heights,
             vector<vector<bool>> &visited) {
        //
        int m = heights.size(), n = heights[0].size();
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto &it : dir) {
                int r = it.first + row, c = it.second + col;

                if (r >= 0 && r < m && c >= 0 && c < n && !visited[r][c] &&
                    (heights[r][c] >= heights[row][col])) {
                    visited[r][c] = true;
                    q.push({r, c});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        vector<vector<int>> ans;

        int m = heights.size(), n = heights[0].size();
#if 0
        //NOTE: This is the Brute force Solution

        auto checkAtlantic = [&](int row, int col) -> bool {
            // Check if the current row and col can reach bottom or right end
            // and the value of new row, col  <= current row, col
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            queue<pair<int, int>> q;
            q.push({row, col});

            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                if ((r == m - 1) || (c == n - 1)) {
                    return true;
                }
                for (auto &it : dir) {
                    int nr = r + it.first, nc = it.second + c;

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        !visited[nr][nc] && heights[nr][nc] <= heights[r][c]) {

                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            return false;
        };
        auto checkPacific = [&](int row, int col) -> bool {
            // Check if the current row and col can reach top or left end
            // and the value of new row, col  <= current row, col
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            queue<pair<int, int>> q;
            q.push({row, col});

            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop();

                if ((r == 0) || (c == 0)) {
                    return true;
                }
                for (auto &it : dir) {
                    int nr = r + it.first, nc = it.second + c;

                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                        !visited[nr][nc] && heights[nr][nc] <= heights[r][c]) {

                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            return false;
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (checkAtlantic(i, j) && checkPacific(i, j)) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
#endif
        // NOTE: We can use the multisource bfs technique we can add the edges
        // to the queue and just mark the cells which can be reached from there
        // the answer will be the common elements in both the pacific and
        // atlantic visited arrays

        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<vector<bool>> pacific(m, vector<bool>(n, false));

        queue<pair<int, int>> qAtlantic, qPacific;

        // Push the Top and Left edges in the qAtlantic
        // TOP
        for (int col = 0; col < n; col++) {
            qPacific.push({0, col});
            pacific[0][col] = true;
        }
        // LEFT
        for (int row = 0; row < m; row++) {
            qPacific.push({row, 0});
            pacific[row][0] = true;
        }

        // Push the Bottom and Right edges in the qPacific
        // Bottom
        for (int col = 0; col < n; col++) {
            qAtlantic.push({m - 1, col});
            atlantic[m - 1][col] = true;
        }
        // Right
        for (int row = 0; row < m; row++) {
            qAtlantic.push({row, n - 1});
            atlantic[row][n - 1] = true;
        }

        bfs(qAtlantic, heights, atlantic);
        bfs(qPacific, heights, pacific);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (atlantic[i][j] && pacific[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
