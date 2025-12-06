#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestOnes(vector<int> &nums, int k) {
    // max length subarray with atmost k zeros
    int zcount = 0, len = 0;
    int l = 0;
    for (int r = 0; r < nums.size(); r++) {
      if (nums[r] == 0) {
        zcount++;
      }
      while (zcount > k) {
        if (nums[l] == 0)
          zcount--;
        l++;
      }
      if (zcount == k)
        len = max(len, r - l + 1);
    }
    return len;
  }
};
int main() {
  vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  int k = 2;
  Solution s;
  cout << s.longestOnes(nums, k) << endl;
}
