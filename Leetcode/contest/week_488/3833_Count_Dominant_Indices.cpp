#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int dominantIndices(vector<int> &nums) {
    int sum = 0;
    if (nums.size() < 2)
      return 0;
    for (int i = 1; i < nums.size(); i++) {
      sum += nums[i];
    }
    int count = 0;
    int r = nums.size() - 1;
    for (int i = 0; i < nums.size(); i++) {
      if (i != 0) {
        sum = sum - nums[i];
        if (sum == 0)
          break;
        int avg = sum / (r - i);
        if (nums[i] > avg)
          count++;
      } else {
        int avg = sum / (r - i);
        if (nums[i] > avg)
          count++;
      }
    }
    return count;
  }
};
