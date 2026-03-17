#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};
class Solution {
  public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Base case
        if (!p && !q) {
            return true;
        }
        // Base case
        if ((p && !q) || (!p && q))
            return false;
        // For current level check both the values
        if (p->val != q->val)
            return false;
        // Trust recusion to bring the previous result
        bool l = isSameTree(p->left, q->left);
        bool r = isSameTree(p->right, q->right);

        // After getting the previous result simple check for your level
        return (l == true && r == true) ? true : false;
    }
};
