#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    stack<int> s;
    vector<int> ans(nums.size(), -1);
    for (int i = 0; i < 2 * nums.size(); i++) {
      int idx = i % nums.size();
      while (!s.empty() && nums[s.top()] < nums[idx]) {
        ans[s.top()] = nums[idx];
        s.pop();
      }
      if (i < nums.size())
        s.push(i);
    }
    return ans;
  }
};
