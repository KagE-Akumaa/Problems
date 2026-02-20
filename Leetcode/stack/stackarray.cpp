#include <bits/stdc++.h>
using namespace std;

class StackArray {
private:
  vector<int> st;

public:
  void push(int x) { st.push_back(x); }
  int top() {
    if (st.empty()) {
      throw runtime_error("Stack is empty");
    }
    return st.back();
  }
  void pop() {
    if (st.empty()) {
      throw runtime_error("Stack is empty");
    }
    st.pop_back();
  }
  bool empty() const { return st.empty(); }
  int size() const { return st.size(); }
};

int main() {
  StackArray s;
  s.push(10);
  s.push(20);

  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  s.pop();
}
