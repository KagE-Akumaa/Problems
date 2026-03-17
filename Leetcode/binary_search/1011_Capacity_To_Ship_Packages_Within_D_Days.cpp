
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int shipWithinDays(vector<int> &weights, int days) {
    int l = *max_element(weights.begin(), weights.end());
    int r = accumulate(weights.begin(), weights.end(), 0);

    int ans = 0;

    auto check = [&](int m) -> bool {
      int d = 0;
      int sum = 0;

      for (int &i : weights) {
        sum += i;
        if (sum > m) {
          sum = i;
          d++;
        }
      }
      d++;
      return d <= days;
    };
    while (l <= r) {
      int m = l + (r - l) / 2;

      if (check(m)) {
        ans = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    return ans;
  }
};
// int main() {
//     vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int days = 1;
//     Solution sol;

//     cout << sol.shipWithinDays(weights, days) << endl;
// }
