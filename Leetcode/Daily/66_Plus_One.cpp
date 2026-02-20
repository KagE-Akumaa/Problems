
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    vector<int> ans;
    int carry = 0;
    int n = digits.size() - 1;
    for (int i = n; i >= 0; i--) {
      if (i == n) {
        int val = digits[i] + 1;
        if (val > 9) {
          ans.push_back(val % 10);
          carry = val / 10;
        } else {
          ans.push_back(val);
        }
        continue;
      }
      if (carry != 0) {
        int val = digits[i] + carry;
        if (val > 9) {
          ans.push_back(val % 10);
          carry = val / 10;
        } else {
          ans.push_back(val);
          carry = 0;
        }
      } else {
        ans.push_back(digits[i]);
      }
    }

    if (carry) {
      ans.push_back(carry);
    }

    return ans;
  }
};
// int main() {
//   vector<int> digits = {8, 9, 9, 9};
//   Solution sol;

//   vector<int> ans = sol.plusOne(digits);
//   for (int &i : ans)
//     cout << i << " ";
//   cout << endl;
// }
