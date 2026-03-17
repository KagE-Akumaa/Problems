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
    void post(TreeNode *root, vector<int> &ans) {
        if (!root)
            return;
        post(root->left, ans);
        post(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root)
            return {};
#if 0
    vector<int> ans;
    post(root, ans);
    return ans;
#endif
        vector<int> ans;
        stack<TreeNode *> st;

        while (root || !st.empty()) {
            while (root) {
                st.push(root);

                ans.push_back(root->val);
                root = root->right;
            }
            root = st.top();
            st.pop();
            root = root->left;
        }
        return ans;
    }
};
