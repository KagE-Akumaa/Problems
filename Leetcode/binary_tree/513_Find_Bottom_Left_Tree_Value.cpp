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
    void helper(TreeNode *root, int currentDepth, int &maxDepth, int &ans) {
        if (!root)
            return;

        if (currentDepth > maxDepth) {
            ans = root->val;
            maxDepth = currentDepth;
        }
        helper(root->left, currentDepth + 1, maxDepth, ans);
        helper(root->right, currentDepth + 1, maxDepth, ans);
    }

    int findBottomLeftValue(TreeNode *root) {
        if (!root)
            return 0;
        // queue<TreeNode *> q;
        // q.push(root);
        // int ans = 0;
        // // Same as left view of a binary tree but instead for every level we
        // // just use the last level value
        // while (!q.empty()) {
        //     int lvl = q.size();
        //     for (int i = 0; i < lvl; i++) {
        //
        //         auto curr = q.front();
        //         q.pop();
        //         if (i == 0)
        //             ans = curr->val;
        //         if (curr->left)
        //             q.push(curr->left);
        //         if (curr->right)
        //             q.push(curr->right);
        //     }
        // }
        // return ans;
        int ans = 0;
        int maxDepth = -1;
        helper(root, 0, maxDepth, ans);
        return ans;
    }
};
