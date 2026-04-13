#include <bits/stdc++.h>
using namespace std;
/*

    1 which means go to the cell to the right. (i.e go from grid[i][j] to
grid[i][j + 1])
2 which means go to the cell to the left. (i.e go from
grid[i][j] to grid[i][j - 1]) 3 which means go to the lower cell. (i.e go from
grid[i][j] to grid[i + 1][j]) 4 which means go to the upper cell. (i.e go from
grid[i][j] to grid[i - 1][j])

Notice that there could be some signs on the cells of the grid that point
outside the grid.

You will initially start at the upper left cell (0, 0). A valid path in the grid
is a path that starts from the upper left cell (0, 0) and ends at the
bottom-right cell (m - 1, n - 1) following the signs on the grid. The valid path
does not have to be the shortest.

You can modify the sign on a cell with cost = 1. You can modify the sign on a
cell one time only.
    */
class Solution {
  public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minCost(vector<vector<int>> &grid) {
        //
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        dist[0][0] = 0;
        deque<pair<int, int>> dq;

        dq.push_back({0, 0});
        pair<int, int> dest{m - 1, n - 1};

        while (!dq.empty()) {
            auto [row, col] = dq.front();
            dq.pop_front();

            for (int i = 0; i < dir.size(); i++) {
                int w = (grid[row][col] == i + 1) ? 0 : 1;

                auto &it = dir[i];

                int r = it.first + row, c = it.second + col;

                if (r >= 0 && c >= 0 && r < m && c < n) {

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
