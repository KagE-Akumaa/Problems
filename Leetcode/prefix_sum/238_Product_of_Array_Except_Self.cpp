#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void print(vector<int> &arr) {
        for (auto &it : arr)
            cout << it << " ";
        cout << endl;
    }
    vector<int> productExceptSelf(vector<int> &nums) {
        // PROOF: How can we get the product of an array index i -> we have to
        // know the product from starting upto i and product from i + 1 to end
        // then we can get the productExceptSelf So, in this we can create a
        // prefix and suffix array and for every ith value the product will be
        // pre[i-1]*suf[i+1] where i > 0 and i < n -1

#if 0
        vector<int> pre(nums.size(), 1), suf(nums.size(), 1);

        int n = nums.size();
        pre[0] = nums[0];
        suf[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] * nums[i];
        }

        for (int i = n - 2; i >= 0; i--) {
            suf[i] = suf[i + 1] * nums[i];
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {

            int lft = i > 0 ? pre[i - 1] : 1;
            int rgt = i < n - 1 ? suf[i + 1] : 1;
            ans.push_back(lft * rgt);
        }
        return ans;
#endif
        // NOTE: This takes O(n) space to build both arrays so now we need to
        // solve the follow up problem

        int n = nums.size();
        22
    }
};
