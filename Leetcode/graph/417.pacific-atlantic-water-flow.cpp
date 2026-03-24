// @leet start
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void helper(queue<pair<int, int>> &pacific, vector<vector<int>> &heights,
                vector<vector<bool>> &visited) {
        int m = heights.size(), n = heights[0].size();
        while (!pacific.empty()) {

            // Need to check the neighbours only valid neighbours are
            // allowed i.e height > curr hegiht NOTE: can go 4 directions so
            // need to check l d u r

            auto [row, col] = pacific.front();
            pacific.pop();
            int curr = heights[row][col];

            if (col - 1 >= 0 && !visited[row][col - 1] &&
                heights[row][col - 1] >= curr) {
                pacific.push({row, col - 1});
                visited[row][col - 1] = true;
            }
            if (col + 1 < n && heights[row][col + 1] >= curr &&
                !visited[row][col + 1]) {
                pacific.push({row, col + 1});

                visited[row][col + 1] = true;
            }

            if (row - 1 >= 0 && heights[row - 1][col] >= curr &&
                !visited[row - 1][col]) {

                pacific.push({row - 1, col});

                visited[row - 1][col] = true;
            }
            if (row + 1 < m && heights[row + 1][col] >= curr &&
                !visited[row + 1][col]) {
                pacific.push({row + 1, col});
                visited[row + 1][col] = true;
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        queue<pair<int, int>> pacific, atlantic;

        int m = heights.size(), n = heights[0].size();

        vector<vector<bool>> visitedP(m, vector<bool>(n, false));
        vector<vector<bool>> visitedA(m, vector<bool>(n, false));
        // Push left and top for pacific

        vector<vector<int>> pans, ans;
        for (int row = 0; row < m; row++) {
            pacific.push({row, 0});
            visitedP[row][0] = true;
        }
        for (int col = 0; col < n; col++) {
            pacific.push({0, col});
            visitedP[0][col] = true;
        }

        // Push right and down for atlantic
        for (int row = 0; row < m; row++) {
            atlantic.push({row, n - 1});
            visitedA[row][n - 1] = true;
        }
        for (int col = 0; col < n; col++) {
            atlantic.push({m - 1, col});
            visitedA[m - 1][col] = true;
        }

        helper(pacific, heights, visitedP);
        helper(atlantic, heights, visitedA);

        // The answer is the common ones

        vector<vector<int>> res;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visitedA[i][j] && visitedP[i][j])
                    res.push_back({i, j});
            }
        }

        return res;
    }
};
// @leet end
