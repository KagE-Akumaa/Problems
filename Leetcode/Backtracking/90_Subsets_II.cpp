
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void genSub(vector<vector<int>> &ans, vector<int> &temp, int start,
                vector<int> &nums) {
        ans.push_back(temp);

        for (int i = start; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
            genSub(ans, temp, i + 1, nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {

        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        genSub(ans, temp, 0, nums);
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 3};
    Solution s;
    auto ans = s.subsetsWithDup(nums);
    for (auto it : ans) {
        for (int i : it)
            cout << i << " ";
    }
}
