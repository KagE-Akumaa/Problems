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
    // points = [ [ 0, 0 ], [ 2, 2 ], [ 3, 10 ], [ 5, 2 ], [ 7, 0 ] ]
    //|xi - xj| + |yi - yj|

    void formEdges(vector<vector<int>> &edges, vector<vector<int>> &points) {
        for (int i = 0; i < points.size(); i++) {
            int u = i;
            for (int j = i + 1; j < points.size(); j++) {
                int v = j;

                int x1 = points[u][0];
                int x2 = points[v][0];

                int y1 = points[u][1];
                int y2 = points[v][1];

                int w = abs(abs(x1 - x2) + abs(y1 - y2));

                edges.push_back({u, v, w});
            }
        }
    }
    void print(vector<vector<int>> &edges) {
        for (auto &it : edges) {
            for (auto &i : it) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    void formGraph(vector<vector<pair<int, int>>> &graph,
                   vector<vector<int>> &edges) {

        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }
    }
    int minCostConnectPoints(vector<vector<int>> &points) {
        vector<vector<int>> edges;

        formEdges(edges, points);

        // NOTE: This is for prims
        vector<vector<pair<int, int>>> graph(points.size());

        formGraph(graph, edges);

        // NOTE: This is using Ksushkal's algorithm
#if 0
        sort(edges.begin(), edges.end(),
             [](const vector<int> &a, const vector<int> &b) {
                 return a[2] < b[2];
             });

        // print(edges);

        int cost = 0;
        int n = points.size();
        Dsu d(n);

        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if (d.find(u) == d.find(v))
                continue;

            d.myUnion(u, v);
            cost += w;
        }

        return cost;
#endif
        // NOTE: Now using prims algorithm

        int cost = 0;
        vector<bool> visited(graph.size(), false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        // NOTE: in pq its weight first - wt, v
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [wt, u] = pq.top();
            pq.pop();

            if (visited[u])
                continue;

            visited[u] = true;
            cost += wt;

            for (auto &nb : graph[u]) {
                if (!visited[nb.first]) {
                    pq.push({nb.second, nb.first});
                }
            }
        }
        return cost;
    }
};

int main() {
    Solution s;
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};

    cout << s.minCostConnectPoints(points) << endl;
}
