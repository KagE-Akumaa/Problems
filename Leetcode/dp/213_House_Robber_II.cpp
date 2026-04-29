#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int rob(vector<int> &nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        auto check = [&](int start, int end) -> int {
            if (start == end) {
                return nums[start];
            }
            int a = nums[start];
            int b = max(nums[start + 1], nums[start]);

            int c = 0;

            for (int i = start + 2; i <= end; i++) {
                c = max(nums[i] + a, b);
                a = b;
                b = c;
            }
            return b;
        };
        return max(check(0, n - 2), check(1, n - 1));
    }
};
