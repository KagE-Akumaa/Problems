#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    /*  if (!head)
        return nullptr;
      ListNode *curr = head, *p = nullptr, *n = nullptr;
      while (curr) {
        n = curr->next;
        curr->next = p;
        p = curr;
        curr = n;
      }
      return p;
      */

    if (!head && !head->next)
      return head;

    ListNode *newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
  }
};
