#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void gen(vector<vector<int>> &ans, vector<int> temp, int start, int n,
           int k) {
    if (temp.size() == k) {
      ans.push_back(temp);
      return;
    }
    if (start > n)
      return;
    for (int i = start; i <= n; i++) {
      temp.push_back(i);
      gen(ans, temp, i + 1, n, k);
      temp.pop_back();
    }
  }
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> temp;
    gen(ans, temp, 1, n, k);
    return ans;
  }
};
