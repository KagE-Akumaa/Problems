#include <bits/stdc++.h>
using namespace std;

class Solution {
      public:
        int find(vector<int> &nums, int i, int target,
                 map<pair<int, int>, int> &mpp) {
                if (i == nums.size() && target == 0) {
                        return 1;
                }
                if (i == nums.size() && target != 0)
                        return 0;

                if (mpp.count({i, target}))
                        return mpp[{i, target}];
                int choosePos = find(nums, i + 1, target - nums[i], mpp);
                // int chooseNeg = find(nums, i + 1, target - (-1 * nums[i]),
                // mpp);
                //  target - (-1 * nums[i])) = target + nums[i]
                int chooseNeg = find(nums, i + 1, target + nums[i], mpp);

                return mpp[{i, target}] = chooseNeg + choosePos;
        }
        int findTargetSumWays(vector<int> &nums, int target) {

                map<pair<int, int>, int> mpp;
                return find(nums, 0, target, mpp);
        }
};

int main() {
        vector<int> nums = {1, 1, 1, 1, 1};
        int target = 3;

        Solution s;

        cout << s.findTargetSumWays(nums, target) << endl;
}
