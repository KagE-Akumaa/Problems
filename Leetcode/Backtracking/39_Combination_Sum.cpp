#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void combSum(vector<vector<int>> &ans, vector<int> temp,
               vector<int> &candidates, int target, int start, int sum) {
    if (sum == target) {
      ans.push_back(temp);
      return;
    }
    if (sum > target)
      return;
    for (int i = start; i < candidates.size(); i++) {
      sum += candidates[i];
      temp.push_back(candidates[i]);
      combSum(ans, temp, candidates, target, i, sum);
      sum -= temp.back();
      temp.pop_back();
    }
  }
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    vector<vector<int>> ans;
    vector<int> temp;
    combSum(ans, temp, candidates, target, 0, 0);
    return ans;
  }
};
int main() {
  vector<int> candidates = {2, 3, 6, 7};
  int target = 7;
  Solution s;
  auto ans = s.combinationSum(candidates, target);
  for (auto &it : ans) {
    for (auto i : it) {
      cout << i << " ";
    }
    cout << endl;
  }
}
