#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minMirrorPairDistance(vector<int> &nums) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++) {
      mpp[nums[i]] = i;
    }
    vector<int> b;
    auto rev = [](int n) -> int {
      int val = 0;
      while (n) {
        int rem = n % 10;
        val = val * 10 + rem;
        n = n / 10;
      }
      return val;
    };
    // b will have the reversed values
    for (int i = 0; i < nums.size(); i++) {
      b.push_back(rev(nums[i]));
    }

    int ans = INT_MAX;
    bool pairFound = false;
    for (int i = 0; i < nums.size(); i++) {
      // now we have to check b[i] if that exist in mapp then we need to get the
      // index of it
      if (mpp.find(b[i]) != mpp.end()) {
        int idx = mpp[b[i]];
        if (i < idx) {
          // we have found the pair
          pairFound = true;

          ans = min(ans, abs(i - idx));
        }
      }
    }
    if (!pairFound)
      return -1;
    return ans;
  }
};
int main() {
  vector<int> nums = {120, 21};
  Solution s;
  cout << s.minMirrorPairDistance(nums) << endl;
}
