#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
  public:
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int minimumEffortPath(vector<vector<int>> &heights) {
        int m = heights.size(), n = heights[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [d, row, col] = pq.top();
            pq.pop();

            if (d > dist[row][col]) {
                continue;
            }

            for (auto &it : dir) {
                int r = it.first + row, c = it.second + col;

                if (r >= 0 && r < m && c < n && c >= 0) {
                    int val = max(d, abs(heights[row][col] - heights[r][c]));

                    if (dist[r][c] > val) {
                        dist[r][c] = val;
                        pq.push({val, r, c});
                    }
                }
            }
        }
        return dist[m - 1][n - 1];
    }
};
int main() {
    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

    Solution s;

    cout << s.minimumEffortPath(heights) << endl;
}
