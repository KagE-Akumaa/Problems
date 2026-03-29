#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
        int m = maze.size(), n = maze[0].size();

        vector<vector<int>> dist(m, vector<int>(n, -1));

        int sr = entrance[0], sc = entrance[1];

        queue<pair<int, int>> q;
        q.push({sr, sc});
        dist[sr][sc] = 0;

        // NOTE: bfs is guarenteed to bring the lowest distance on the first try
        // use that to early return
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto &it : dir) {
                int r = it.first + row, c = it.second + col;

                if (r >= 0 && r < m && c >= 0 && c < n && dist[r][c] == -1 &&
                    maze[r][c] != '+') {
                    dist[r][c] = 1 + dist[row][col];

                    if (r == 0 || r == m - 1 || c == 0 || c == n - 1) {
                        return dist[r][c];
                    }
                    q.push({r, c});
                }
            }
        }
        //
        // // NOTE: Now check the border rows, cols
        // int md = INT_MAX;
        // // Left side
        // for (int row = 0; row < m; row++) {
        //     if (dist[row][0] != -1 && dist[row][0] != 0) {
        //         md = min(md, dist[row][0]);
        //     }
        //     if (dist[row][n - 1] != -1 && dist[row][n - 1] != 0) {
        //         md = min(md, dist[row][n - 1]);
        //     }
        // }
        // // Upper side
        // for (int col = 0; col < n; col++) {
        //     if (dist[0][col] != -1 && dist[0][col] != 0) {
        //
        //         md = min(md, dist[0][col]);
        //     }
        //     if (dist[m - 1][col] != -1 && dist[m - 1][col] != 0) {
        //         md = min(md, dist[0][m - 1]);
        //     }
        // }
        // // right side
        // //
        // // for (int row = 0; row < m; row++) {
        // //     if (dist[row][n - 1] == -1)
        // //         continue;
        // //     md = min(md, dist[row][n - 1]);
        // // }
        // //
        // // for (int col = 0; col < n; col++) {
        // //     if (dist[m - 1][col] == -1)
        // //         continue;
        // //     md = min(md, dist[m - 1][col]);
        // // }
        //
        // for (auto &it : dist) {
        //     for (auto &i : it)
        //         cout << i << " ";
        //     cout << endl;
        // }

        return -1;
    }
};
