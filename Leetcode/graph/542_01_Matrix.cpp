#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
#if 0
        //NOTE: This works but we can improve the space complexity by return and updating the original matrix

        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size(), -1));

        int m = mat.size(), n = mat[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto &it : dir) {
                int r = it.first + row, c = it.second + col;

                if (r >= 0 && r < m && c >= 0 && c < n && ans[r][c] == -1) {
                    ans[r][c] = ans[row][col] + 1;
                    q.push({r, c});
                }
            }
        }
        return ans;
#endif
        int m = mat.size(), n = mat[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (mat[i][j] == 0) {
                    q.push({i, j});
                } else {
                    mat[i][j] = -1;
                }
            }
        }

        while (!q.empty()) {
            auto &[row, col] = q.front();
            q.pop();

            for (auto &it : dir) {
                int r = it.first + row, c = it.second + col;

                if (r >= 0 && r < m && c >= 0 && c < n && mat[r][c] == -1) {
                    q.push({r, c});

                    mat[r][c] = mat[row][col] + 1;
                }
            }
        }
        return mat;
    }
};
