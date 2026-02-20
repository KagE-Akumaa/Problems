#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string getString(string &s) {
    string st;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '#') {
        if (!st.empty()) {
          st.pop_back();
        }
      } else
        st.push_back(s[i]);
    }
    return st;
  }
  void checkStr(string &a) {
    for (int i = 1; i < a.size(); i++) {
      if (a[i] == '#') {
        a[i - 1] = '0';
        a[i] = '0';

        int l = 0, r = a.size() - 1;
        while (l <= r) {
          if (a[l] == '0') {
            swap(a[l], a[r]);
            r--;
          } else
            l++;
        }
      }
    }
    while (!a.empty() && a.back() == '0')
      a.pop_back();
  }
  bool backspaceCompare(string s, string t) {
    checkStr(s);
    checkStr(t);
    cout << s << endl;
    cout << t << endl;
    return s == t;
  }
};
int main() {
  string s = "ab##";
  string t = "c#d#";

  Solution sol;
  cout << sol.backspaceCompare(s, t) << endl;
}
