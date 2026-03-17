#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void permUni(vector<vector<int>> &ans, vector<int> temp, vector<int> &nums,
               vector<bool> &visited) {
    if (temp.size() == nums.size()) {
      ans.push_back(temp);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])
        continue;
      if (visited[i])
        continue;
      temp.push_back(nums[i]);
      visited[i] = true;
      permUni(ans, temp, nums, visited);
      temp.pop_back();
      visited[i] = false;
    }
  }
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> visited(nums.size(), false);
    sort(nums.begin(), nums.end());

    permUni(ans, temp, nums, visited);
    return ans;
  }
};

int main() {
  vector<int> nums = {1, 1, 2};
  Solution s;
  auto ans = s.permuteUnique(nums);
  for (auto &it : ans) {
    for (auto &i : it)
      cout << i << " ";
    cout << endl;
  }
}
