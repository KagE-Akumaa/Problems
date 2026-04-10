#include <bits/stdc++.h>
using namespace std;

int primMST(int V, vector<vector<pair<int, int>>> &adj) {
    // adj[u] = list of {neighbor, weight}
    // return total MST weight

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int total = 0;
    vector<bool> visited(V, false);
    // IDEA: Just add the current node based on weight in the priority_queue
    // then check if it's already visited we skip it else we add its neighbor
    // into the priority_queue based on the weight
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (visited[u])
            continue;

        visited[u] = true;
        total += w;
        for (auto &nb : adj[u]) {
            if (!visited[nb.first]) {
                pq.push({nb.second, nb.first});
            }
        }
    }
    return total;
}

int main() {
    // Test 1 — the graph we just traced
    // Expected output: 6  (edges: 0-1=1, 1-2=2, 2-3=3)
    int V1 = 4;
    vector<vector<pair<int, int>>> adj1(V1);
    adj1[0].push_back({1, 1});
    adj1[1].push_back({0, 1});
    adj1[1].push_back({2, 2});
    adj1[2].push_back({1, 2});
    adj1[2].push_back({3, 3});
    adj1[3].push_back({2, 3});
    adj1[0].push_back({3, 4});
    adj1[3].push_back({0, 4});
    cout << primMST(V1, adj1) << "\n";

    // Test 2 — star graph, all edges from center node 0
    // Expected output: 6  (edges: 0-1=1, 0-2=2, 0-3=3)
    int V2 = 4;
    vector<vector<pair<int, int>>> adj2(V2);
    adj2[0].push_back({1, 1});
    adj2[1].push_back({0, 1});
    adj2[0].push_back({2, 2});
    adj2[2].push_back({0, 2});
    adj2[0].push_back({3, 3});
    adj2[3].push_back({0, 3});
    cout << primMST(V2, adj2) << "\n";

    // Test 3 — two paths to same node, pick cheaper
    // Edges: 0-1=5, 0-2=1, 1-2=2, 1-3=1
    // Expected output: 4  (edges: 0-2=1, 2-1=2... wait, is 0-1=5 or go via 2?)
    // MST: 0-2(1), 2-1(2), 1-3(1) = 4
    int V3 = 4;
    vector<vector<pair<int, int>>> adj3(V3);
    adj3[0].push_back({1, 5});
    adj3[1].push_back({0, 5});
    adj3[0].push_back({2, 1});
    adj3[2].push_back({0, 1});
    adj3[1].push_back({2, 2});
    adj3[2].push_back({1, 2});
    adj3[1].push_back({3, 1});
    adj3[3].push_back({1, 1});
    cout << primMST(V3, adj3) << "\n";

    return 0;
}
