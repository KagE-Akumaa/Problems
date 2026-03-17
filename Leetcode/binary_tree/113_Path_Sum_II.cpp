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
    void helpre(TreeNode *root, vector<vector<int>> &ans, vector<int> &temp,
                int targetSum) {
        if (!root)
            return;
        temp.push_back(root->val);
        targetSum -= root->val;
        if (targetSum == 0 && (!root->left && !root->right)) {
            ans.push_back(temp);
        }
        helpre(root->left, ans, temp, targetSum);
        helpre(root->right, ans, temp, targetSum);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        if (!root)
            return {};

        vector<vector<int>> ans;
        vector<int> temp;
        helpre(root, ans, temp, targetSum);
        return ans;
    }
};
