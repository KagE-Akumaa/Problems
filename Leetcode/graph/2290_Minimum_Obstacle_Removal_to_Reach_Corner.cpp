#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int minimumObstacles(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        dist[0][0] = 0;

        deque<pair<int, int>> dq;
        dq.push_back({0, 0});

        while (!dq.empty()) {
            auto [row, col] = dq.front();
            dq.pop_front();

            for (auto &it : dir) {

                int r = it.first + row, c = it.second + col;

                if (r < m && r >= 0 && c < n && c >= 0) {
                    int w = (grid[r][c] == 0) ? 0 : 1;

                    if (dist[r][c] > dist[row][col] + w) {
                        dist[r][c] = dist[row][col] + w;

                        if (w == 0) {
                            dq.push_front({r, c});
                        } else {
                            dq.push_back({r, c});
                        }
                    }
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};
