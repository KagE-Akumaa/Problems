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
    void genResponse(vector<string> &ans, vector<string> &temp) {
        string res = "";
        for (auto &st : temp) {
            if (!res.empty()) {
                res += "->";
            }
            res += st;
        }
        ans.push_back(res);
    }
    void helper(TreeNode *root, vector<string> &ans, vector<string> &temp) {
        if (!root)
            return;

        temp.push_back(to_string(root->val));
        if (!root->left && !root->right) {

            genResponse(ans, temp);
            temp.pop_back();
            return;
        }
        helper(root->left, ans, temp);
        helper(root->right, ans, temp);

        temp.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode *root) {
        if (!root)
            return {};

        vector<string> ans;
        vector<string> temp;
        helper(root, ans, temp);
        return ans;
    }
};
