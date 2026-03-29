#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n, -1));

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    height[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto &it : dir) {
                int r = it.first + row, c = it.second + col;

                if (r < m && r >= 0 && c < n && c >= 0 && height[r][c] == -1) {

                    height[r][c] = 1 + height[row][col];
                    q.push({r, c});
                }
            }
        }
        return height;
    }
};
