#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    void print(vector<vector<int>> &grid) {
        for (auto &it : grid) {
            for (auto &i : it) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (int col = 0; col < n; col++) {
            grid[0][col] = 1;
        }

        for (int row = 0; row < m; row++) {
            grid[row][0] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }
        }
        //        print(grid);
        return grid[m - 1][n - 1];
    }
};

int main() {
    int m = 3, n = 2;
    Solution s;

    cout << s.uniquePaths(m, n) << endl;
}
