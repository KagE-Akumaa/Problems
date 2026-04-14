#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumJumps(vector<int> &forbidden, int a, int b, int x) {
        int mf = *max_element(forbidden.begin(), forbidden.end());
        unordered_map<int, int> mpp;

        for (int i = 0; i < forbidden.size(); i++) {
            mpp[forbidden[i]] = i;
        }
        int upperBound = 6000;
        queue<pair<int, bool>> q;

        q.push({0, false});
        int d = 0;
        vector<vector<bool>> visited(upperBound + 1, vector<bool>(2, false));
        visited[0][0] = true;

        auto validate = [&](int val) -> bool {
            // Three condtions -
            // 1. not in forbidden array
            // 2. cannot be negative
            // 3. should be in range upperBound

            if (mpp.find(val) != mpp.end())
                return false;
            if (val < 0)
                return false;
            if (val > upperBound)
                return false;

            return true;
        };
        while (!q.empty()) {
            int lvl = q.size();
            while (lvl--) {
                auto [pos, flag] = q.front();
                q.pop();

                if (pos == x) {
                    return d;
                }
                if (!flag) {
                    // Means we can forward as well as backward

                    if (validate(pos + a) && !visited[pos + a][0]) {
                        q.push({pos + a, false});
                        visited[pos + a][0] = true;
                    }
                    if (validate(pos - b) && !visited[pos - b][1]) {
                        q.push({pos - b, true});
                        visited[pos - b][1] = true;
                    }
                }
                if (flag) {
                    // Means we can only go forward
                    if (validate(pos + a) && !visited[pos + a][0]) {
                        q.push({pos + a, false});
                        visited[pos + a][0] = true;
                    }
                }
            }
            d++;
        }
        return -1;
    }
};
