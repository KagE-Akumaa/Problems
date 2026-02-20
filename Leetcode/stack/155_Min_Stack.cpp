#include <bits/stdc++.h>
using namespace std;
class MinStack {
public:
  stack<int> s;
  priority_queue<int, vector<int>> pq;
  MinStack() {}

  void push(int val) {
    s.push(val);
    pq.push(val);
  }

  void pop() {
    int tp = pq.top();
    if (!s.empty()) {
      int stp = s.top();
      if (stp == tp) {
        // remove from both
        pq.pop();
        s.pop();
      }
    }
  }

  int top() {
    if (!s.empty()) {
      return s.top();
    }
    return -1;
  }

  int getMin() {
    if (!pq.empty()) {
      return pq.top();
    }
    return -1;
  }
};

/**a
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
