#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findDuplicate(vector<int> &nums) {
        // NOTE: Nums contain n + 1 element which belongs to [1, n] inclusive
        // and there exist an element which appears more than once
        // We got the general solution but its using O(n) space which is not
        // allowed

        // NOTE: We have defined range from 1 to n so how can we find the
        // element which occurs twice? without using any space and not modifing
        // the array?
        // we can sum the element and minus it from the original sum
        // The sum approach fails when there exist more than one duplicate
        // values

        // NOTE: Then what can we do?
        //
        int n = nums.size() - 1;
    }
};
