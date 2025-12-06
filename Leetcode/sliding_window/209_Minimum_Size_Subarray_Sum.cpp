#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int len = INT_MAX;
    int l = 0;
    int sum = 0;
    for (int r = 0; r < nums.size(); r++) {
      sum += nums[r];
      while (sum >= target && l <= r) {
        len = min(len, r - l + 1);
        sum -= nums[l];
        l++;
      }
    }
    return len == INT_MAX ? 0 : len;
  }
};
int main() {
  vector<int> nums = {1, 4, 4};
  int target = 4;
  Solution s;
  cout << s.minSubArrayLen(target, nums) << endl;
}
