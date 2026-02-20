#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
  stack<int> fi, se;
  MyQueue() {}

  void push(int x) { fi.push(x); }

  int pop() {
    while (!fi.empty()) {
      se.push(fi.top());
      fi.pop();
    }
    int val = se.top();
    se.pop();
    while (!se.empty()) {
      fi.push(se.top());
      se.pop();
    }
    return val;
  }

  int peek() {
    while (!fi.empty()) {
      se.push(fi.top());
      fi.pop();
    }
    int val = se.top();
    while (!se.empty()) {
      fi.push(se.top());
      se.pop();
    }
    return val;
  }

  bool empty() { return fi.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
