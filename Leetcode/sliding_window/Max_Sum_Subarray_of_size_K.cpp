#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int maxSubarraySum(vector<int> &arr, int k) {
    // code here
    int sum = 0, ans = 0;

    int l = 0;
    for (int r = 0; r < arr.size(); r++) {
      sum += arr[r];

      if (r - l + 1 > k) {
        sum -= arr[l];
        l++;
      }
      if (r - l + 1 == k)
        ans = max(sum, ans);
    }
    return ans;
  }
};
