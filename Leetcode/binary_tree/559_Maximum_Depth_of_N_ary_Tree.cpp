#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) { val = _val; }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
  public:
    int md = 0;
    void helper(Node *root, int d) {
        if (!root)
            return;
        md = max(md, d);
        for (auto &it : root->children) {
            helper(it, d + 1);
        }
    }
    int maxDepth(Node *root) {
        // if (!root)
        //     return 0;
        // helper(root, 1);
        // return md;
        if (!root)
            return 0;

        int depth = 0;
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            int lvl = q.size();
            for (int i = 0; i < lvl; i++) {
                auto curr = q.front();
                q.pop();

                for (auto &child : curr->children) {
                    q.push(child);
                }
            }
            depth++;
        }
        return depth;
    }
};
