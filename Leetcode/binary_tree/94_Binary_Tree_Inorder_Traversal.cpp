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
  void inor(TreeNode *root, vector<int> &ans) {
    if (!root)
      return;
    inor(root->left, ans);
    ans.push_back(root->val);
    inor(root->right, ans);
  }
  vector<int> inorderTraversal(TreeNode *root) {
#if 0
    if (!root)
      return {};
    vector<int> ans;
    inor(root, ans);
    return ans;
#endif
    vector<int> ans;
    stack<TreeNode *> st;
    while (root || !st.empty()) {
      while (root) {
        st.push(root);
        root = root->left;
      }
      root = st.top();
      st.pop();
      ans.push_back(root->val);
      root = root->right;
    }
    return ans;
  }
};
