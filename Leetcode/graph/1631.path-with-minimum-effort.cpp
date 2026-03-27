// @leet start
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    bool dfs(pair<int, int> src, vector<vector<int>> &heights,
             vector<vector<bool>> &visited, pair<int, int> dest, int effort,
             int m, int n) {
        //
        auto [row, col] = src;

        visited[row][col] = true;
        if (row == dest.first && col == dest.second) {
            return true;
        }
        for (auto &it : dir) {
            int r = it.first + row, c = it.second + col;

            if (r >= 0 && r < m && c >= 0 && c < n && !visited[r][c]) {

                int mval = abs(heights[r][c] - heights[row][col]);
                if (mval > effort) {
                    continue;
                }
                if (dfs({r, c}, heights, visited, dest, effort, m, n))
                    return true;
            }
        }

        return false;
    }
    bool bfs(pair<int, int> src, vector<vector<int>> &heights,
             vector<vector<bool>> &visited, pair<int, int> dest, int effort,
             int m, int n) {
        //
        queue<pair<int, int>> q;
        q.push(src);
        visited[src.first][src.second] = true;

        while (!q.empty()) {

            auto [row, col] = q.front();
            q.pop();
            if (row == dest.first && col == dest.second) {
                return true;
            }

            for (auto &it : dir) {
                int r = it.first + row, c = it.second + col;

                if (r >= 0 && r < m && c >= 0 && c < n && !visited[r][c]) {
                    int mval = abs(heights[r][c] - heights[row][col]);
                    if (mval > effort)
                        continue;

                    q.push({r, c});
                    visited[r][c] = true;
                }
            }
        }
        return false;
    }
    int minimumEffortPath(vector<vector<int>> &heights) {
        // what is the range?
        // min abs dif - max abs dif

        int l = 0, r = 1e6;

        int m = heights.size(), n = heights[0].size();
        // NOTE: Binary search with dfs and bfs implementation
        // auto check = [&](int effort) -> bool {
        //     vector<vector<bool>> visited(m, vector<bool>(n, false));
        //     pair<int, int> src = {0, 0}, dest = {m - 1, n - 1};
        //
        //     // return dfs(src, heights, visited, dest, effort, m, n);
        //     return bfs(src, heights, visited, dest, effort, m, n);
        // };
        // int ans = INT_MAX;
        // while (l <= r) {
        //     int mid = l + (r - l) / 2;
        //
        //     if (check(mid)) {
        //         ans = min(mid, ans);
        //         r = mid - 1;
        //     } else {
        //         l = mid + 1;
        //     }
        // }
        // return ans;

        // NOTE: USING DIJKSTAR : -

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        // Source
        dist[0][0] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;

        // NOTE: we want the sorting according to the effort so put the effort
        // first it goes lexographically
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [d, row, col] = pq.top();
            pq.pop();

            for (auto &it : dir) {
                int r = it.first + row, c = it.second + col;

                if (r >= 0 && r < m && c >= 0 && c < n) {
                    int newEffort =
                        max(d, abs(heights[r][c] - heights[row][col]));

                    if (newEffort < dist[r][c]) {
                        dist[r][c] = newEffort;
                        pq.push({newEffort, r, c});
                    }
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};
// @leet end
