#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int myAtoi(string s) {
    if (s.empty()) {
      return 0;
    }
    // Remove whitespaces

    string str = "";
    int idx = 0;
    long long num = 0;
    while (s[idx] == ' ') {
      idx++;
    }
    int sign = 1;
    if (idx < s.size() && s[idx] == '-') {
      sign = -1 * sign;
    }
    for (int i = idx; i < s.size(); i++) {
      if (i == idx && (s[i] == '-' || s[i] == '+')) {
        continue;
      }
      if (!isdigit(s[i]))
        break;
      if (num * 10 > INT_MAX || (num * 10 + (s[i] - '0')) > INT_MAX) {
        return sign == -1 ? INT_MIN : INT_MAX;
      }
      if (s[i] == '0' && num == 0)
        continue;
      num = num * 10 + (s[i] - '0');
    }

    return num * sign;
  }
};
// int main() {
//   string s = "2147483648";
//   Solution sol;

//   cout << sol.myAtoi(s) << endl;
// }
