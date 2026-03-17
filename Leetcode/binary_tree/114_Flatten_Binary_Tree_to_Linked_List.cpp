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
    void helper(TreeNode *root, TreeNode *temp) {
        if (!root)
            return;

        temp->right = root;
        helper(root->left, temp->right);
        helper(root->right, temp->right);
    }

    void flatten(TreeNode *root) {
        if (!root)
            return;
        TreeNode *temp = new TreeNode(root->val, nullptr, nullptr);
        helper(root, temp);
        root = temp;
    }
};
