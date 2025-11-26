#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int l = 0, r = height.size() - 1;
    int leftmax = height[0], rightmax = height[height.size() - 1];
    int c = 0;

    while (l <= r) {
      if (leftmax < rightmax) {
        c += (leftmax - height[l] < 0) ? 0 : leftmax - height[l];
        leftmax = max(leftmax, height[l]);
        l++;
      } else {
        c += (rightmax - height[r] < 0) ? 0 : rightmax - height[r];
        rightmax = max(rightmax, height[r]);
        r--;
      }
    }
    return c;
  }
};
