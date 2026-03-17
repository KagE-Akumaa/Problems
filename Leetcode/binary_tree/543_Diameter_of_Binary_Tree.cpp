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
    int dia = 0;
    int helper(TreeNode *root) {
        if (!root)
            return 0;
        int l = helper(root->left);
        int r = helper(root->right);

        dia = max(dia, l + r);

        return 1 + max(l, r);
    }
    int diameterOfBinaryTree(TreeNode *root) {
        if (!root)
            return 0;
        helper(root);
        return dia;
    }
};
