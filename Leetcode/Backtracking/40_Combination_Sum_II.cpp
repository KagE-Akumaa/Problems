#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void comb2(vector<vector<int>> &ans, vector<int> temp,
             vector<int> &candidates, int target, int start, int sum) {
    if (target == 0) {
      ans.push_back(temp);
      return;
    }
    if (target < 0)
      return;
    for (int i = start; i < candidates.size(); i++) {
      if (i > start && candidates[i] == candidates[i - 1])
        continue;
      temp.push_back(candidates[i]);
      comb2(ans, temp, candidates, target - candidates[i], i + 1, sum);
      temp.pop_back();
    }
  }
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    comb2(ans, temp, candidates, target, 0, 0);
    return ans;
  }
};

int main() {
  vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
  int target = 8;
  Solution s;
  auto ans = s.combinationSum2(candidates, target);
  for (auto &it : ans) {
    for (auto &i : it) {
      cout << i << " ";
    }
    cout << endl;
  }
}
