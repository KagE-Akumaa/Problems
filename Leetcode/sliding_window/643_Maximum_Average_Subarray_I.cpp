#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double findMaxAverage(vector<int> &nums, int k) {
    double ans = 0;
    int l = 0;
    double sum = 0;
    for (int r = 0; r < nums.size(); r++) {
      sum += nums[r];

      if (r - l + 1 > k) {
        sum -= nums[l];
        l--;
      }

      if (r - l + 1 == k) {
        ans = max(ans, sum / k);
      }
    }
    return ans;
  }
};
