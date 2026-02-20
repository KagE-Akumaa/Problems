#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int pivotIndex(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    int lsum = 0;
    for (int i = 0; i < nums.size(); i++) {
      int rsum = sum - lsum - nums[i];

      if (lsum == rsum) {
        return i;
      }
      lsum += nums[i];
    }
    return -1;
  }
};

int main() {
  vector<int> nums = {1, 7, 3, 6, 5, 6};
  Solution sol;
  cout << sol.pivotIndex(nums) << endl;
}
