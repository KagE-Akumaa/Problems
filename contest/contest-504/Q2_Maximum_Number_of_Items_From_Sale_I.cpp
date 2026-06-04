#include <bits/stdc++.h>
using namespace std;

class Solution {
      public:
        int helper(vector<vector<int>> &items, int budget,
                   vector<pair<int, int>> &v, int i) {
                if (budget == 0) {
                        // Calculate
                        int copies = 0;

                        for (int i = 0; i < v.size(); i++) {
                                for (int j = 0; j < v.size(); j++) {
                                        if (i == j)
                                                continue;

                                        if (v[i].first % v[j].first == 0) {

                                                copies++;
                                        }
                                }
                        }

                        cout << v.size() << endl;
                        return copies;
                }
                if (i >= items.size())
                        return 0;

                if (budget >= items[i][1]) {
                        v.push_back({items[i][0], items[i][1]});
                        int pick =
                            1 + helper(items, budget - items[i][1], v, i);
                        v.pop_back();

                        int not_pick = helper(items, budget, v, i + 1);

                        return max(pick, not_pick);
                }

                return helper(items, budget, v, i + 1);
        }
        int maximumSaleItems(vector<vector<int>> &items, int budget) {

                vector<pair<int, int>> v;

                return helper(items, budget, v, 0);
        }
};
int main() {
        vector<vector<int>> items{{2, 4}, {3, 2}, {4, 1}, {6, 4}, {12, 4}};
        int budget = 8;

        Solution s;

        cout << s.maximumSaleItems(items, budget) << endl;
}
