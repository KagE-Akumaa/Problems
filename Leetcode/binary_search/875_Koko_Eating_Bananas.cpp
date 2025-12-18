#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int l = 1, r = *max_element(piles.begin(), piles.end());

    // If possible for k hours then possible for k + 1 need to check for check
    // -1
    int ans = INT_MAX;
    auto check = [&](int m) -> bool {
      // How to check for k-> speed in h hours ?
      int hours = 0;
      for (int i = 0; i < piles.size(); i++) {
        if (piles[i] <= m) {
          hours++;
        } else {
          hours += (piles[i] + m - 1) / m;
        }
      }
      return hours <= h;
    };
    while (l <= r) {
      int m = l + (r - l) / 2;

      if (check(m)) {
        ans = min(ans, m);
        // Move r to mid -1
        r = m - 1;
      } else
        l = m + 1;
    }
    return ans;
  }
};
int main() {
  vector<int> nums = {3, 6, 7, 11};
  int h = 8;
  Solution s;

  cout << s.minEatingSpeed(nums, h);
}
