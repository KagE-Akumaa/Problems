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
    int widthOfBinaryTree(TreeNode *root) {
        if (!root)
            return 0;

        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});
        long long width = 0;
        while (!q.empty()) {
            int lvl = q.size();
            long long lidx = q.front().second;
            long long ridx = q.back().second;

            width = max(width, ridx - lidx + 1);

            for (int i = 0; i < lvl; i++) {
                auto [curr, idx] = q.front();
                q.pop();
                // Normalising step same as - (ridx - lidx) - (lidx - lidx)  =
                // ridx - lidx
                long long index = idx - lidx;
                if (curr->left) {
                    q.push({curr->left, 2 * index});
                }
                if (curr->right) {
                    q.push({curr->right, 2 * index + 1});
                }
            }
        }
        return (int)width;
    }
};
