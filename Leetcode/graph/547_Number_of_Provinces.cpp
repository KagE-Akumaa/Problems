#include <bits/stdc++.h>
using namespace std;

struct Dsu {
    vector<int> parent, rnk;

    Dsu(int n) {
        parent.resize(n);
        rnk = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void myUnion(int x, int y) {
        int x1 = find(x);
        int y1 = find(y);

        if (x1 == y1) {
            return;
        }
        if (rnk[x1] > rnk[y1]) {
            parent[y1] = x1;
        } else if (rnk[y1] > rnk[x1]) {
            parent[x1] = y1;
        } else {
            parent[y1] = x1;
            rnk[x1]++;
        }
    }
};
class Solution {
  public:
    int findCircleNum(vector<vector<int>> &isConnected) {

        int n = isConnected.size();
        Dsu d(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // NOTE: if the isConnected[i][j] == 1 that means city i is
                // Connected to city j so we can form a set for both of them
                if (isConnected[i][j] == 1) {
                    d.myUnion(i, j);
                }
            }
        }
        // NOTE: Now we have sets like {1,2} and {3} so what this means?
        // it is just saying that there are 2 provinces in total city 1 - city 2
        // form 1 provinces and city - 3 forms one
        // Now question arises how could we count that from our dsu?
        // The answer is simple we have a parent array which stores the parent
        // of a set or basically we just set one element from the set to be
        // their leader and that is true for every set (every set will have its
        // leader)
        // So, now we just want to get the number of leaders and we have the
        // answer Tip:- think mathematically logic will be there then it just
        // becomes implementation problem :)

        unordered_set<int> st;

        for (int i = 0; i < n; i++) {
            // NOTE: This is how we find the parent or leader of a set :)
            st.insert(d.find(i));
        }

        return st.size();
    }
};
