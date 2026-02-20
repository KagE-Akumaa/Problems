#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void makeStr(int dig, string &str) {
    string ans;
    while (dig--) {
      ans += str;
    }
    str = std::move(ans);
    reverse(str.begin(), str.end());
    cout << str << endl;
  }
  string decodeString(string s) {

    auto pushStr = [&](stack<char> &st, string &str) {
      for (auto &ch : str) {
        st.push(ch);
      }
    };
    auto formdigit = [&](stack<char> &st) -> string {
      string number;
      while (!st.empty() && isdigit(st.top())) {
        number.push_back(st.top());
        st.pop();
      }
      reverse(number.begin(), number.end());
      return number;
    };
    stack<char> st;
    for (char &ch : s) {
      if (ch != ']') {
        st.push(ch);
      } else {
        // we got a ']'
        // need to pop till we find a number;
        string str = "";
        while (!st.empty() && !isdigit(st.top())) {
          if (st.top() != '[')
            str.push_back(st.top());
          st.pop();
        }
        // need to multiply by that factor digit is in st.top()
        if (!st.empty()) {
          int dig = stoi(formdigit(st));
          makeStr(dig, str);
          pushStr(st, str);
        } else
          st.push(ch);
      }
    }
    string ans;
    while (!st.empty()) {
      ans.push_back(st.top());
      st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
int main() {
  string s = "100[leetcode]";
  Solution sol;

  cout << sol.decodeString(s) << endl;
}
