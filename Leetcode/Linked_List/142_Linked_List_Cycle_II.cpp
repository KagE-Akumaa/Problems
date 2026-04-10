#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
  public:
    ListNode *detectCycle(ListNode *head) {
        if (!head)
            return nullptr;
        ListNode *slow = head, *fast = head, *cycleNode = nullptr;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Found cylce
                cycleNode = slow;
                break;
            }
        }

        if (!cycleNode)
            return cycleNode;

        slow = head;
        while (slow != cycleNode) {
            slow = slow->next;
            cycleNode = cycleNode->next;
        }
        return cycleNode;
    }
};
