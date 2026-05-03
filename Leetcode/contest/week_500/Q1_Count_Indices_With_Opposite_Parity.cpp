#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> countOppositeParity(vector<int> &nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int count = 0;
            bool even;
            if (nums[i] & 1) {
                even = false;
            } else
                even = true;
            for (int j = i + 1; j < nums.size(); j++) {
                bool val;
                if (nums[j] & 1)
                    val = false;
                else
                    val = true;

                if (even && !val) {
                    count++;
                } else if (!even && val)
                    count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
