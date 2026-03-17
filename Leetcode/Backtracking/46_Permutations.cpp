#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void genPermutation(vector<vector<int>> &ans, vector<int> temp,
                      vector<int> &nums, vector<bool> &visited) {
    if (temp.size() == nums.size()) {
      ans.push_back(temp);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (visited[i])
        continue;
      temp.push_back(nums[i]);
      visited[i] = true;
      genPermutation(ans, temp, nums, visited);
      temp.pop_back();
      visited[i] = false;
    }
  }
  vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> visited(nums.size(), 0);
    genPermutation(ans, temp, nums, visited);
    return ans;
  }
};

int main() {
  vector<int> nums = {1, 2, 3};
  Solution s;
  auto ans = s.permute(nums);
  for (auto &it : ans) {
    for (auto &i : it)
      cout << i << " ";
    cout << endl;
  }
}
