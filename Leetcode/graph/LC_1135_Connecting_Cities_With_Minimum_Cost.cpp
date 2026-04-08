#include <bits/stdc++.h>
using namespace std;
class Solution {
    /* Input:  n = 4, connections = [[1,2,1],[2,3,2],[3,4,3],[1,4,10],[2,4,5]]
        Output: 6
Reason: 1-2 (1) + 2-3 (2) + 3-4 (3) = 6
        Ignored 1-4 and 2-4 as they would form cycles
        */
  public:
    struct Dsu {
        vector<int> parent, rnk;
        Dsu(int n) {
            parent.resize(n);
            rnk.assign(n, 0);

            iota(parent.begin(), parent.end(), 0);
        }

        int find(int x) {
            if (x == parent[x])
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
    void print(vector<vector<int>> &graph) {
        for (int i = 0; i < graph.size(); i++) {
            for (auto &it : graph[i]) {
                cout << it << " ";
            }
            cout << endl;
        }
    }
    int minimumCost(int n, vector<vector<int>> &connections) {
        //

        sort(connections.begin(), connections.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 return a[2] < b[2];
             });
        // print(connections);
        Dsu d(n + 1);

        int cost = 0;
        for (auto &it : connections) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if (d.find(u) == d.find(v)) {
                continue;
            }
            d.myUnion(u, v);
            cost += w;
        }
        unordered_set<int> st;
        for (int i = 1; i <= n; i++) {
            st.insert(d.find(i));
        }
        if (st.size() > 1)
            return -1;
        return cost;
        // print(graph);
    }
};

int main() {
    Solution s;
    vector<vector<int>> connections = {
        {1, 2, 1}, {2, 3, 2}, {3, 4, 3}, {1, 4, 10}, {2, 4, 5}};
    int n = 4;
    vector<vector<int>> connections2 = {{1, 3, 5}, {1, 2, 1}, {2, 3, 2}};
    int n1 = 3;
    cout << s.minimumCost(n1, connections2) << endl;
}
