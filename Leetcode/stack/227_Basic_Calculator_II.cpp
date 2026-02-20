#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int calculate(string s) {
    vector<int> ans;
    char op = '+';
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
      if (isdigit(s[i])) {
        num = num * 10 + (s[i] - '0');
      }
      if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {
        if (op == '+') {
          ans.push_back(num);
        } else if (op == '-') {
          ans.push_back(-num);
        } else if (op == '/') {
          int top = ans.back();
          ans.pop_back();
          ans.push_back(top / num);
        } else if (op == '*') {
          int top = ans.back();
          ans.pop_back();
          ans.push_back(top * num);
        }
        op = s[i];
        num = 0;
      }
    }
    return accumulate(ans.begin(), ans.end(), 0);
  }
};
int main() {
  string s = " 3+5 / 2 ";
  Solution sol;

  cout << sol.calculate(s) << endl;
}
