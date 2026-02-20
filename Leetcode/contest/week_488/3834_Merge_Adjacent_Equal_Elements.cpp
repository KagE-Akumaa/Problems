#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void checkStack(vector<long long> &st) {
    if (st.size() == 1)
      return;
    long long a = st.back();
    st.pop_back();
    bool enter = false;
    while (!st.empty() && a == st.back()) {
      enter = true;
      long long vpush = 2 * a;
      st.pop_back();
      if (!st.empty() && vpush == st.back()) {
        a = vpush;
      } else {
        // a = st.top();
        st.push_back(vpush);
      }
    }
    if (!enter)
      st.push_back(a);
  }
  vector<long long> mergeAdjacent(vector<int> &nums) {
    vector<long long> st;
    st.push_back(nums[0]);
    long long p = st.back();
    for (int i = 1; i < nums.size(); i++) {
      if (!st.empty() && st.back() == nums[i]) {
        st.pop_back();
        long long curr = 2 * nums[i];
        st.push_back(curr);
        checkStack(st);
      } else {
        st.push_back(nums[i]);
      }
    }
    vector<long long> ans;
    return st;
  }
};
int main() {
  vector<int> nums = {2, 1, 1, 2};
  Solution s;

  vector<long long> ans = s.mergeAdjacent(nums);
  for (auto &it : ans)
    cout << it << " ";
}
