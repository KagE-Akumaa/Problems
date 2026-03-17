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
    int msum = INT_MIN;
    int helper(TreeNode *root) {

        if (!root)
            return 0;
        int l = max(0, helper(root->left));
        int r = max(0, helper(root->right));

        msum = max(msum, root->val + l + r);
        return root->val + max(l, r);
    }
    int maxPathSum(TreeNode *root) {
        if (!root) {
            return 0;
        }
        helper(root);
        return msum;
    }
};
