#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void print(vector<int> &arr) {
        for (auto &it : arr)
            cout << it << " ";
        cout << endl;
    }
    vector<int> findValidElements(vector<int> &nums) {
        int n = nums.size();
#if 0
        //NOTE: Using 2 prefix arrays

        vector<int> left(n, 0), right(n, 0);
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            left[i] = max(left[i - 1], nums[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(right[i + 1], nums[i]);
        }
        //
        // print(left);
        // print(right);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (i == 0 || i == n - 1) {
                ans.push_back(nums[i]);
                continue;
            }

            if (nums[i] > left[i -1] || nums[i] >= right[i + 1]) {
                ans.push_back(nums[i]);
            }
        }
        return ans;
#endif
        // NOTE: USING ONLY THE RIGHT ARRAY
        vector<int> right(n, 0);
        right[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(nums[i], right[i + 1]);
        }

        int left = nums[0];
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == n - 1) {
                ans.push_back(nums[i]);
                left = nums[i];
                continue;
            }

            if (nums[i] > left || nums[i] > right[i + 1]) {
                ans.push_back(nums[i]);
            }
            left = max(left, nums[i]);
        }
        return ans;
    }
};

// int main() {
//     vector<int> nums = {1, 2, 4, 2, 3, 2};
//     Solution s;
//     vector<int> ans = s.findValidElements(nums);
//     for (auto &it : ans)
//         cout << it << " ";
//     cout << endl;
// }
