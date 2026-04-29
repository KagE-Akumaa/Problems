#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string sortVowels(string s) {
        string str;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u')
                str.push_back(s[i]);
        }
        sort(str.begin(), str.end());

        int j = 0;
        string ans;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                ans.push_back(str[j]);
                j++;
                continue;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};

int main() {
    string s = "leetcode";
    Solution sol;
    string str = sol.sortVowels(s);
    cout << str << endl;
}
