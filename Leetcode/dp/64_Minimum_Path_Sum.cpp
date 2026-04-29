#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    // OBSERVATION: 0,0 -> m -1, n -1 -> path with minimum sum -> find all path
    // return min -> brute force fails as the complexity to get all the possible
    // paths is 2^(m+n) (also we need to go right and down only)
    // Better way -> what does a cell i, j represents if we want to get min sum
    // -> it can represents the min sum to reach i, j
    // So, dp[i][j] -> minsum to reach i, j now the base case would be dp[0][0]
    // = grid[0][0] and we can go down and right so dp[0][1] (right) = dp[0][0]
    // + grid[0][1] and dp[1][0] (down) = dp[0][0] + grid[1][0] and we can fill
    // the top and left fully
    void dfs(int row, int col, vector<vector<bool>> &visited,
             vector<vector<int>> &grid, int m, int n, int &sum, int &ans) {
        visited[row][col] = true;

        if (row == m - 1 && col == n - 1) {
            ans = min(sum, ans);
            visited[row][col] = false;
            return;
        }

        for (auto &it : dir) {
            int r = it.first + row, c = it.second + col;

            if (r >= 0 && r < m && c >= 0 && c < n && !visited[r][c]) {
                sum = sum + grid[r][c];
                dfs(r, c, visited, grid, m, n, sum, ans);
                sum -= grid[r][c];
            }
        }
        visited[row][col] = false;
    }
    void print(vector<vector<int>> &grid) {
        for (auto &it : grid) {
            for (auto &i : it) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    int minPathSum(vector<vector<int>> &grid) {
        //
        int m = grid.size(), n = grid[0].size();

#if 0
        //NOTE: Brute force didn't worked

        int sum = grid[0][0];
        int ans = INT_MAX;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        dfs(0, 0, visited, grid, m, n, sum, ans);

        return ans;
#endif

#if 0 
        //NOTE: Using O(m*n) extra space

        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        // Fill the top layer
        for (int col = 1; col < n; col++) {
            dp[0][col] = dp[0][col - 1] + grid[0][col];
        }
        for (int row = 1; row < m; row++) {
            dp[row][0] = dp[row - 1][0] + grid[row][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] =
                    min(dp[i][j - 1] + grid[i][j], dp[i - 1][j] + grid[i][j]);
            }
        }

        print(dp);
        return dp[m - 1][n - 1];
#endif
        // NOTE: Using constant Space modifying the grid

        for (int col = 1; col < n; col++) {
            grid[0][col] += grid[0][col - 1];
        }

        for (int row = 1; row < m; row++) {
            grid[row][0] += grid[row - 1][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] = grid[i][j] + min(grid[i][j - 1], grid[i - 1][j]);
            }
        }
        return grid[m - 1][n - 1];
    }
};
int main() {
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

    Solution s;
    cout << s.minPathSum(grid) << endl;
}
