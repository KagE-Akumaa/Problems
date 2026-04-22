#include <bits/stdc++.h>
using namespace std;
// down, up, right, left
vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void print(vector<vector<char>> &grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}
void solve() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n, '#'));

    pair<int, int> src, dest;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char ch;

            cin >> ch;

            if (ch == 'A') {
                src = {i, j};
            }
            if (ch == 'B') {
                dest = {i, j};
            }

            grid[i][j] = ch;
        }
    }

    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<pair<int, int>>> parent(m, vector<pair<int, int>>(n));
    vector<vector<char>> move(m, vector<char>(n));

    queue<pair<int, int>> q;
    q.push(src);
    visited[src.first][src.second] = true;

    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        if (make_pair(row, col) == dest)
            break;

        for (auto &it : dir) {
            int r = it.first + row, c = it.second + col;

            if (r >= 0 && r < m && c >= 0 && c < n && !visited[r][c] &&
                grid[r][c] != '#') {
                visited[r][c] = true;
                parent[r][c] = {row, col};

                if (it.first == 1 && it.second == 0) {
                    move[r][c] = 'D';
                } else if (it.first == -1 && it.second == 0) {
                    move[r][c] = 'U';
                } else if (it.first == 0 && it.second == 1) {
                    move[r][c] = 'R';
                } else {
                    move[r][c] = 'L';
                }

                q.push({r, c});
            }
        }
    }

    if (!visited[dest.first][dest.second]) {
        cout << "NO" << endl;
        return;
    }

    string path;
    pair<int, int> curr = dest;

    while (curr != src) {
        path.push_back(move[curr.first][curr.second]);
        curr = parent[curr.first][curr.second];
    }

    reverse(path.begin(), path.end());

    cout << "YES" << endl;
    cout << path.size() << endl;
    cout << path << endl;
}
int main() {
    int t = 1;
    while (t--) {
        solve();
    }
}
