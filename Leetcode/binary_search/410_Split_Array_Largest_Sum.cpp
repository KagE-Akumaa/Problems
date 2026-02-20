#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int splitArray(vector<int> &nums, int k) {
    int right = accumulate(nums.begin(), nums.end(), 0);
    int left = *max_element(nums.begin(), nums.end());
    int ans = 0;
    auto check = [&](int mid, int k) -> bool {
      int count = 1;
      int sum = 0;
      for (int &i : nums) {
        if (sum + i > mid) {
          count++;
          sum = 0;
        }
        sum += i;
      }
      return count <= k;
    };
    while (left <= right) {
      int mid = left + (right - left) / 2;

      if (check(mid, k)) {
        // update ans
        right = mid - 1;
        ans = mid;
      } else {
        left = mid + 1;
      }
    }
    return ans;
  }
};

int main() {
  vector<int> nums = {7, 2, 5, 10, 8};
  Solution sol;
  int k = 2;
  cout << sol.splitArray(nums, k);
}
