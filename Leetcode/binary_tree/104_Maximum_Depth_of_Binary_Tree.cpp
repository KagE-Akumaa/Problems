
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
    int maxDepth(TreeNode *root) {
        if (!root)
            return 0;

        // return 1 + max(maxDepth(root->left), maxDepth(root->right));
        int depth = 0;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            int lvl = q.size();
            auto curr = q.front();
            q.pop();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);

            depth++;
        }
        return depth;
    }
};
