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
    int mval = 0;
    pair<int, int> helper(TreeNode *root) {
        // base case
        if (!root)
            return {-1001, 0};
        // for the current level if i can have the previous value and the length
        // for which the values are equal we trust recursion to get the answer
        auto [lval, llen] = helper(root->left);
        auto [rval, rlen] = helper(root->right);
        // for current level if lval == current value then we can use the llen
        // or we have to set it to 0 same for rval
        int larm = lval == root->val ? llen : 0;
        int rarm = rval == root->val ? rlen : 0;

        // we want the max length for which the values are equal so global
        // variable or pass by reference
        mval = max(mval, larm + rarm);

        // return what you wanted for current level so that previous level can
        // have it
        return {root->val, 1 + max(larm, rarm)};
    }
    int longestUnivaluePath(TreeNode *root) {
        if (!root)
            return 0;
        helper(root);
        return mval;
    }
};
