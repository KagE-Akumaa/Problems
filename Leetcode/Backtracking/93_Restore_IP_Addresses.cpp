#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool is_valid(string &str) {}
  void helper(vector<vector<string>> &ans, vector<string> &temp, string &s,
              int start) {
    if (start == s.size()) {
      ans.push_back(temp);
      return;
    }
    for (int i = start; i < s.size(); i++) {
      string part = s.substr(start, i - start + 1);
      if (!is_valid(part)) {
        continue;
      }
      temp.push_back(part);
      helper(ans, temp, s, i + 1);
      temp.pop_back();
    }
  }
  vector<string> restoreIpAddresses(string s) {
    vector<vector<string>> ans;
    vector<string> temp;
    helper(ans, temp, s, 0);
    vector<string> res;
    for (auto &it : ans) {
      for (auto &i : it)
        res.push_back(i);
    }
    return res;
  }
};
