#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool checkValid(stack<char> st, int count) {
    // need to find the / count the char in between if > 2 not valid
    if (count == 2) {
      int c = 0;
      while (!st.empty() && st.top() != '/') {
        c++;
        st.pop();
      }
      if (c > 2)
        return false;
      return true;
    } else {
      int c = 0;
      while (!st.empty() && st.top() != '/') {
        c++;
        st.pop();
      }
      if (c > 1)
        return true;
      return false;
    }
  }
  void giveValid(stack<char> &st) {
    int count = 0;
    if (checkValid(st, 2)) {
      while (!st.empty() && count < 2) {
        if (st.top() == '/')
          count++;
        st.pop();
      }
      st.push('/');
      return;
    }
    st.push('/');
  }
  string simplifyPath(string path) {
    stack<char> st;
    int count = 0;
    // First is to make sure every directory is spaced by one /
    for (char &ch : path) {
      if (ch == '/' && !st.empty() && st.top() == '/') {
        continue;
      } else {
        if (ch == '.') {
          st.push(ch);
          count++;
        } else if (ch != '.' && !st.empty() && st.top() == '.') {
          if (ch != '/') {
            // consider this valid
            count++;
            st.push(ch);
          } else if (count == 2) {
            // some function
            giveValid(st);
          } else if (count == 1) {
            if (!checkValid(st, 1))
              st.pop();
            else
              st.push('/');
          } else
            st.push(ch);
          count = 0;
        } else
          st.push(ch);
      }
    }
    string s;
    cout << count << endl;
    if (count) {
      if (count == 1) {
        if (!checkValid(st, 1))
          st.pop();
      } else if (count == 2)
        giveValid(st);
    }
    while (!st.empty() && st.top() == '/' && st.size() > 2) {
      st.pop();
    }
    while (!st.empty()) {
      s.push_back(st.top());
      st.pop();
    }
    // for (char &ch : path) {
    // }
    reverse(s.begin(), s.end());
    return s;
  }
};
int main() {
  string s = "/abcde.";
  Solution sol;
  cout << sol.simplifyPath(s) << endl;
}
