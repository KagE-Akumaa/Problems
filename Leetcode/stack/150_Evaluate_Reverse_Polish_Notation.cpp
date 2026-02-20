#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> st;

    auto evaluate = [&](string &op, int a, int b) -> int {
      if (op == "+") {
        return a + b;
      } else if (op == "-") {
        return a - b;
      } else if (op == "/") {
        return a / b;
      } else {
        return a * b;
      }
    };
    vector<string>::iterator it = tokens.begin();
    for (it = tokens.begin(); it != tokens.end(); it++) {
      string s = *it;
      if (s == "/" || s == "+" || s == "-" || s == "*") {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        int result = evaluate(s, b, a);
        st.push(result);

      } else {
        st.push(stoi(s));
      }
    }
    return st.top();
  }
};
int main() {
  Solution s;
  vector<string> tokens = {"4", "13", "5", "/", "+"};

  cout << s.evalRPN(tokens) << endl;
}
