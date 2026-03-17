#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void helper(vector<string> &ans, string &temp, int open, int close, int n) {
        if (open == n and close == n) {
            ans.push_back(temp);
            return;
        }
        if (open < n) {
            temp.push_back('(');
            helper(ans, temp, open + 1, close, n);
        }
        if (close < open) {
            temp.push_back(')');
            helper(ans, temp, open, close + 1, n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        helper(ans, temp, 0, 0, n);
        return ans;
    }
};
int main() {
    int n = 3;
    Solution s;
    auto ans = s.generateParenthesis(n);
    for (auto &it : ans) {
        for (auto &i : it) {
            cout << i << "";
        }
        cout << endl;
    }
}
