
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {

    if (nums.empty())
      return {-1, -1};
    int l = -1, u = -1;

    auto searchLow = [&]() -> int {
      int l = 0, r = nums.size() - 1;
      int ans = -1;
      while (l <= r) {
        int m = l + (r - l) / 2;
        if (nums[m] == target) {
          // if we find the element we need to go more left to get the starting
          // index so for that we need to move r to m -1
          ans = m;
          r = m - 1;
        } else if (nums[m] < target) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
      return ans;
    };
    auto searchHigh = [&]() -> int {
      int l = 0, r = nums.size() - 1;
      int ans = -1;
      while (l <= r) {
        int m = l + (r - l) / 2;
        if (nums[m] == target) {
          // need to find the last element == target so now move the left to m +
          // 1 to make the search in that region
          ans = m;
          l = m + 1;
        } else if (nums[m] > target) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      }
      return ans;
    };
    l = searchLow();
    u = searchHigh();

    return {l, u};
  }
};
