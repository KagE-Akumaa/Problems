#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void print(vector<int> &pre) {
        for (auto &it : pre)
            cout << it << " ";

        cout << endl;
    }
    bool canPartition(vector<int> &nums) {
        vector<int> pre(nums.size(), 0), suf(nums.size(), 0);

        sort(nums.begin(), nums.end());
        int n = nums.size();
        pre[0] = nums[0];
        suf[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }

        for (int i = n - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] + nums[i];
        }

        print(pre);
        print(suf);

        for (int i = 0; i < n; i++) {
            int val = pre[i];

            if (i + 1 < n) {
                if (val == suf[i + 1])
                    return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1, 5, 11, 5};

    Solution s;

    cout << s.canPartition(nums);
}
