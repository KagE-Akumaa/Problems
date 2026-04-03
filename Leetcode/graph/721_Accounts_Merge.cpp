#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    struct Dsu {
        vector<int> parent, rnk;
        Dsu(int n) {
            parent.resize(n);
            rnk.assign(n, 0);

            iota(parent.begin(), parent.end(), 0);
        }
        int find(int x) {
            if (x == parent[x]) {
                return x;
            }
            return parent[x] = find(parent[x]);
        }

        void myUnion(int u, int v) {
            int x = find(u);
            int y = find(v);

            if (x == y)
                return;

            if (rnk[x] > rnk[y])
                parent[y] = x;
            else if (rnk[y] > rnk[x]) {
                parent[x] = y;
            } else {
                parent[y] = x;
                rnk[x]++;
            }
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        //
        int n = accounts.size();
        Dsu d(n);
        unordered_map<string, int> eaccount;

        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 0; j < accounts[i].size(); j++) {
                // NOTE: for an email if that already exists in the map we get
                // the index of account where it exists and union it with the
                // current account index
                if (j == 0) {
                    // NOTE: We ignore the name
                    continue;
                }

                if (eaccount.find(accounts[i][j]) != eaccount.end()) {
                    // NOTE: Means its in the map
                    int accountIdx = eaccount[accounts[i][j]];
                    // Now we union the accountIdx with current accountIdx which
                    // is i
                    d.myUnion(accountIdx, i);
                } else {
                    eaccount[accounts[i][j]] = i;
                }
            }
        }

        unordered_map<int, set<string>> mp;

        for (int i = 0; i < n; i++) {
            int parent = d.find(i);
            for (int j = 1; j < accounts[i].size(); j++) {
                mp[parent].insert(accounts[i][j]);
            }
        }

        vector<vector<string>> ans;

        for (auto &it : mp) {
            int parent = it.first;
            vector<string> temp;

            temp.push_back(accounts[parent][0]);

            for (auto &email : it.second) {
                temp.push_back(email);
            }

            ans.push_back(temp);
        }
        return ans;
    }
};
