#include <bits/stdc++.h>
using namespace std;
/*
LC 286 — Walls and Gates
You are given an m x n grid rooms initialized with these three values:

-1 — a wall or obstacle
0 — a gate
2147483647 (INF) — an empty room

Fill each empty room with the distance to its nearest gate. If it is impossible
to reach a gate, leave it as INF. You must modify the grid in place — no return
value. Example 1: Input:
[[2147483647, -1,          0,           2147483647],
 [2147483647,  2147483647, 2147483647, -1         ],
 [2147483647, -1,          2147483647, -1         ],
 [0,          -1,          2147483647,  2147483647]]

Output:
[[3, -1, 0,  1],
 [2,  2, 1, -1],
 [1, -1, 2, -1],
 [0, -1, 3,  4]]
Example 2:
Input:  [[0]]
Output: [[0]]
Constraints:

1 <= m, n <= 250
rooms[i][j] is either -1, 0, or 2147483647
*/

class Solution {
  public:
    vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    void wallsAndGates(vector<vector<int>> &rooms) {
        queue<pair<int, int>> q;

        // NOTE: Step 1 is to get the source node
        // Source nodes are the nodes which have the information in this case
        // the distance from a room is not given so the source node should not
        // be the room it should be the gate for which the distance is 0

        int m = rooms.size(), n = rooms[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // NOTE: Step 2 Push the source nodes into the queue
                if (rooms[i][j] == 0)
                    q.push({i, j});
            }
        }

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto &it : dir) {
                int r = it.first + row, c = it.second + col;

                if (r >= 0 && r < m && c >= 0 && c < n &&
                    rooms[r][c] == 2147483647) {

                    // NOTE: Step 3 Check the neighbours if not visited based on
                    // the condition like in this case room == 2147483647 then
                    // its not visited then update for this room and add this to
                    // the queue so that we can process its neighbours
                    int d = 1 + rooms[row][col];
                    rooms[r][c] = d;
                    q.push({r, c});
                }
            }
        }
    }
};
