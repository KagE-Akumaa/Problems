#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countElements(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int c = 0;

    auto check = [&](int target) -> int {
      int l = 0, r = nums.size() - 1;
      while (l <= r) {
        int m = l + (r - l) / 2;

        if (nums[m] > target) {
          r = m - 1;
        } else
          l = m + 1;
      }
      return l;
    };
    for (int i = 0; i < nums.size(); i++) {
      // we need to find the index for which the target is < the next greater
      // value
      int idx = check(nums[i]);

      if ((nums.size() - idx) >= k)
        c++;
    }
    return c;
  }
};
int main() {
  vector<int> nums = {3, 1, 2};
  int k = 1;

  Solution s;
  cout << s.countElements(nums, k) << endl;
}
