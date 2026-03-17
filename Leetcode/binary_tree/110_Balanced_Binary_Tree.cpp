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
    int helper(TreeNode *root) {
        if (!root)
            return 0;
        int l = helper(root->left);
        int r = helper(root->right);

        if (abs(l - r) > 1) {
            return -1;
        }
        int h = 1 + max(l, r);
        return h;
    }
    bool isBalanced(TreeNode *root) {
        if (!root)
            return true;
        return helper(root) != -1;
    }
};
