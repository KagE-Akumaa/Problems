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
    bool TreeChecker(TreeNode *root, TreeNode *subRoot, bool &check) {
        if (!root && !subRoot) {
            return true;
        }

        if ((!root && subRoot) || (root && !subRoot)) {
            return false;
        }

        if (root->val != subRoot->val) {
            return false;
        }

        return TreeChecker(root->left, subRoot->left, check) &&
               TreeChecker(root->right, subRoot->right, check);
    }
    void helper(TreeNode *root, TreeNode *subRoot, bool &check) {
        if (!root) {
            return;
        }
        if (root->val == subRoot->val) {
            // FOUND ANY ENTRY POINT -> check in this tree is is a same tree

            bool found = TreeChecker(root, subRoot, check);

            if (found)
                check = true;
        }

        if (check)
            return;

        helper(root->left, subRoot, check);
        helper(root->right, subRoot, check);
    }
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (!root && !subRoot)
            return false;

        bool check = false;
        helper(root, subRoot, check);
        return check;
    }
};
