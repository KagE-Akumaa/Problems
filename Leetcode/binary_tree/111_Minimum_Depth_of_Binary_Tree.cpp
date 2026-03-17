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
    int mini = INT_MIN;
    void helper(TreeNode *root, int currDepth) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            mini = min(mini, currDepth);
        }
        helper(root->left, currDepth + 1);
        helper(root->right, currDepth + 1);
    }
    int minDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        helper(root, 0);
        return mini;
    }
};
