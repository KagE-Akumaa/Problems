#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int swimInWater(vector<vector<int>> &grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;

        // NOTE: Dist represents the time taken from 1 cell to other
        dist[0][0] = grid[0][0];

        // dist/time, row, col
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) {
            auto [d, row, col] = pq.top();
            pq.pop();

            if (d > dist[row][col])
                continue;

            for (auto &it : dir) {
                int r = it.first + row, c = it.second + col;

                // validate r and c
                if (r >= 0 && r < n && c >= 0 && c < n) {
                    // if value at grid[r][c] is same as row, col we can go
                    // directly to that cell so time is same as value at
                    // dist[row][col]

                    int newDist = max(grid[r][c], dist[row][col]);

                    if (dist[r][c] > newDist) {
                        dist[r][c] = newDist;
                        pq.push({dist[r][c], r, c});
                    }
                }
            }
        }
        return dist[n - 1][n - 1];
    }
};
