#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    int r = *max_element(piles.begin(), piles.end());
    int l = 1;

    int ans = 0;
    auto check = [&](int mid) -> int {
      int hours = 0;
      for (int &i : piles) {
        if (i % mid == 0)
          hours++;
        else
          hours += (i / mid) + 1;
      }
      return hours <= h;
    };
    while (l <= r) {
      int m = l + (r - l) / 2;

      if (check(m)) {
        ans = m;
        r = m - 1;
      } else
        l = m + 1;
    }
    return ans;
  }
};
