#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    unordered_map<int, int> mpp;
    // this will have the val and nge of nums2
    stack<int> s;
    bool entered = false;
    for (int i = 0; i < nums2.size(); i++) {
      if (i == 0) {
        s.push(i);
        continue;
      }
      while (!s.empty() && nums2[s.top()] < nums2[i]) {
        entered = true;
        mpp[nums2[s.top()]] = nums2[i];
        s.pop();
      }
      s.push(i);
    }

    for (auto &it : mpp) {
      cout << it.first << " " << it.second << endl;
    }
    vector<int> ans;
    for (int i = 0; i < nums1.size(); i++) {
      if (mpp.find(nums1[i]) == mpp.end()) {
        ans.push_back(-1);
      } else
        ans.push_back(mpp[nums1[i]]);
    }
    return ans;
  }
};
int main() {
  Solution s;
  vector<int> nums1 = {4, 1, 2}, nums2 = {1, 3, 4, 2};

  vector<int> ans = s.nextGreaterElement(nums1, nums2);

  for (auto &it : ans) {
    cout << it << " ";
  }
}
