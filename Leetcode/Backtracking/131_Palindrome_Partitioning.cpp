#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool is_valid(string &s, int l, int r) {
        while (l <= r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    void BackPart(vector<vector<string>> &ans, vector<string> &temp, string &s,
                  int start) {
        if (start == s.size()) {
            ans.push_back(temp);
        }
        for (int i = start; i < s.size(); i++) {
            if (!is_valid(s, start, i))
                continue;
            temp.push_back(s.substr(start, i - start + 1));
            BackPart(ans, temp, s, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        BackPart(ans, temp, s, 0);
        return ans;
    }
};

int main() {
    string s = "aab";
    Solution sol;
    auto ans = sol.partition(s);
    for (auto &it : ans) {
        for (auto &i : it)
            cout << i << " ";
        cout << endl;
    }
}
