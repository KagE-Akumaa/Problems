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
            if (parent[x] == x)
                return x;

            return parent[x] = find(parent[x]);
        }

        void myUnion(int u, int v) {
            int x = find(u);
            int y = find(v);

            if (x == y)
                return;
            if (rnk[x] > rnk[y]) {
                parent[y] = x;
            } else if (rnk[y] > rnk[x]) {
                parent[x] = y;
            } else {
                parent[y] = x;
                rnk[x]++;
            }
        }
    };
    vector<vector<int>>
    findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {
        for (int i = 0; i < edges.size(); i++)
            edges[i].push_back(i); // edges[i] = [u, v, w, originalIndex]
        sort(edges.begin(), edges.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 return a[2] < b[2];
             });
        int mc = 0;
        Dsu d(n);
        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if (d.find(u) == d.find(v)) {
                continue;
            }

            mc += w;
            d.myUnion(u, v);
        }

        // NOTE: mc is the minimum cost from the mst now we have to check if for
        // remove any node if the weight becomes more than this it means it's
        // critical This we need to do for every ith edge

        auto checkCritical = [&](int index) {
            int cost = 0;
            Dsu myD(n);

            for (int i = 0; i < edges.size(); i++) {
                if (i == index)
                    continue;

                int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];

                if (myD.find(u) == myD.find(v))
                    continue;

                cost += w;
                myD.myUnion(u, v);
            }
            unordered_set<int> st;
            for (int i = 0; i < n; i++) {
                st.insert(myD.find(i));
            }
            if (st.size() > 1) {
                return INT_MAX;
            }

            return cost;
        };
        auto checkPseudoCritical = [&](int index) {
            int cost = 0;
            Dsu myD(n);

            int x = edges[index][0];
            int y = edges[index][1];
            int wt = edges[index][2];

            cost += wt;
            myD.myUnion(x, y);

            for (auto &it : edges) {
                int u = it[0];
                int v = it[1];
                int w = it[2];

                if (myD.find(u) == myD.find(v)) {
                    continue;
                }

                cost += w;
                myD.myUnion(u, v);
            }
            return cost;
        };
        vector<int> critical, pseudo;
        for (int i = 0; i < edges.size(); i++) {
            int criticalcostCheck = checkCritical(i);
            int pseudocostCheck = checkPseudoCritical(i);
            if (criticalcostCheck > mc) {
                // Means this is a critical edge
                critical.push_back(edges[i][3]);
            } else if (pseudocostCheck == mc) {
                pseudo.push_back(edges[i][3]);
            }
        }

        vector<vector<int>> ans;
        ans.push_back(critical);
        ans.push_back(pseudo);

        for (auto &it : critical) {
            cout << it << " ";
        }
        return ans;
    }
};
