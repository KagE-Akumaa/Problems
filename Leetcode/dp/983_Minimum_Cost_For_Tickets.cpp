#include <bits/stdc++.h>
using namespace std;

class Solution {
      public:
        int helper(vector<int> &days, vector<int> &cost, int i) {
                if (i >= days.size()) {
                        return INT_MAX;
                }

                int day1, day2, day3;

                if (1 >= days[i]) {
                        int pick = cost[0] + helper(days, cost, i + 1);
                        int not_pick = helper(days, cost, i + 1);

                        day1 = min(pick, not_pick);
                }
                if (7 >= days[i]) {
                        int pick = cost[1] + helper(days, cost, i + 1);
                        int not_pick = helper(days, cost, i + 1);

                        day2 = min(pick, not_pick);
                }
                if (30 >= days[i]) {
                        int pick = cost[2] + helper(days, cost, i + 1);
                        int not_pick = helper(days, cost, i + 1);

                        day3 = min(pick, not_pick);
                }

                return min({day1, day2, day3});
        }
        int mincostTickets(vector<int> &days, vector<int> &costs) {
                //

                return helper(days, costs, 0);
        }
};
