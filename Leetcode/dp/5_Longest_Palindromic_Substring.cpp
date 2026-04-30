#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    string longestPalindrome(string s) {

        auto check = [&](string str) -> bool {
            int l = 0, r = str.size() - 1;
            while (l <= r) {
                if (str[l] != str[r])
                    return false;
                l++;
                r--;
            }
            return true;
        };
        string final;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                string str = s.substr(i, j - i + 1);
                if (check(str)) {
                    if (str.size() > final.size()) {
                        final = str;
                        //  cout << str << endl;
                    }
                }
            }
        }
        return final;
    }
};

int main() {
    string s = "babad ";
    Solution S;
    cout << S.longestPalindrome(s) << endl;
}
