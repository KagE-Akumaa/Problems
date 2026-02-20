#include <bits/stdc++.h>
using namespace std;
class Node {
protected:
  int data;
  Node *next;

public:
  Node(int data) : data(data), next(nullptr) {}

  friend class StackLinked;
};

class StackLinked {
private:
  Node *head;
  int sz;

public:
  StackLinked() : head(nullptr), sz(0) {}

  void push(int x) {
    Node *n = new Node(x);
    n->next = head;
    head = n;
    sz++;
  }
  int top() const {
    if (head == nullptr)
      throw runtime_error("Stack is empty");
    return head->data;
  }
  void pop() {
    if (head == nullptr) {
      throw runtime_error("Stack is empty");
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    sz--;
  }

  bool empty() const { return head == nullptr; }

  int size() const { return sz; }
  ~StackLinked() {
    while (head) {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }
};
int main() {
  StackLinked st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(40);

  cout << st.size() << endl;

  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
}
