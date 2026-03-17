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
    void pre(TreeNode *root, vector<int> &ans) {
        if (!root)
            return;
        ans.push_back(root->val);
        pre(root->left, ans);
        pre(root->left, ans);
    }
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root)
            return {};
#if 0
    vector<int> ans;
    pre(root, ans);
    return ans;
#endif
        vector<int> ans;
        stack<TreeNode *> st;
        while (root || !st.empty()) {
            while (root) {
                ans.push_back(root->val);
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            root = root->right;
        }
        return ans;
    }
};
