#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int l = 0, r = height.size() - 1;

    int ans = 0, d = 0;
    while (l <= r) {
      int h = height[l] <= height[r] ? height[l] : height[r];
      int w = r - l;
      ans = max(h * w, ans);

      if (height[l] > height[r])
        r--;
      else
        l++;
    }
    return ans;
  }
};
