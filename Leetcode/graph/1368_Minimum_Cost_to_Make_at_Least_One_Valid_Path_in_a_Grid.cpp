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
// Binary search can be applied for this if possible to do in k cost then
// possible for > k cost the range could be the 0 to m * n (suppose change
// required for all cells)
class Solution {
  public:
    int minCost(vector<vector<int>> &grid) {
        //
        int m = grid.size(), n = grid[0].size();
        int l = 0, r = m * n;

        int ans = INT_MAX;

        auto check = [&](int mid) -> bool {
            // How to check for k counts ?
        };
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(mid)) {
                ans = min(ans, mid);
                r = mid - 1;
            } else
                l = mid + 1;
        }
    }
};
