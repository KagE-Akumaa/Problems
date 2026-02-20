#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    vector<char> st;
    for (char &ch : s) {
      if (ch == ')' || ch == '}' || ch == ']') {
        // need to check the top if it matches then fine else false
        if (st.empty())
          return false;
        char t = st.back();
        st.pop_back();

        if ((t == '(' && ch != ')') || (t == '{' && ch != '}') ||
            (t == '[' && ch != ']')) {
          return false;
        }
      } else if (ch == '(' || ch == '{' || ch == '[')
        st.push_back(ch);
      else
        return false;
    }
    return st.empty() ? true : false;
  }
};
