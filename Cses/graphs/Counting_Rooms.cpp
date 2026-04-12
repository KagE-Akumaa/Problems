#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs(int row, int col, vector<vector<char>> &mat, int m, int n) {
    if (mat[row][col] == '.') {
        mat[row][col] = '#';
        for (auto &it : dir) {
            int r = row + it.first, c = col + it.second;

            if (r < m && r >= 0 && c < n && c >= 0) {
                dfs(r, c, mat, m, n);
            }
        }
    }
}
void solve() {
    int n, m;
    cin >> m >> n;

    vector<vector<char>> mat(m, vector<char>(n));

    for (auto &it : mat) {
        for (auto &i : it)
            cin >> i;
    }

    // NOTE: # is wall and . is room

    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == '.') {
                dfs(i, j, mat, m, n);
                count++;
            }
        }
    }
    cout << count << endl;
}
int main() {
    int t = 1;
    while (t--) {
        solve();
    }
}
