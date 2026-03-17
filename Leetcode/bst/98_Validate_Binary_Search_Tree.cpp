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
    bool helper(TreeNode *root, TreeNode *min, TreeNode *maxi) {
        if (!root)
            return true;

        if (min && root->val <= min->val)
            return false;
        if (maxi && root->val >= maxi->val) {
            return false;
        }

        return helper(root->left, min, root) && helper(root->right, root, maxi);
    }
    bool isValidBST(TreeNode *root) {
        if (!root)
            return true;
        return helper(root, nullptr, nullptr);
    }
};
