#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<char> findPosition(pair<int, int> &source, vector<vector<char>> &mat) {

    int m = mat.size(), n = mat[0].size();
    queue<pair<int, int>> q;
    q.push(source);
    mat[source.first][source.second] = '#';

    vector<char> ans;
    while (!q.empty()) {
        auto [row, col] = q.front();
        q.pop();

        if (mat[row][col] == 'B') {
            // Found the destination
            return ans;
        }

        for (auto &it : dir) {
            int r = it.first + row, c = it.second + col;

            if (r >= 0 && r < m && c < n && c >= 0 &&
                (mat[r][c] == '.' || mat[r][c] == 'B')) {
                q.push({r, c});
                mat[r][c] = '#';
                if (it.first == 1 && it.second == 0) {
                    ans.push_back('D');
                } else if (it.first == -1 && it.second == 0) {
                    ans.push_back('U');
                } else if (it.first == 0 && it.second == 1) {
                    ans.push_back('R');
                } else {
                    ans.push_back('L');
                }
            }
        }
    }
    return {};
}
void solve() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> mat(m, vector<char>(n));
    for (auto &it : mat) {
        for (auto &i : it)
            cin >> i;
    }

    // NOTE: Source is A and dest is B so find the source first

    pair<int, int> source;
    bool found = false;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 'A') {
                // Found the source
                source.first = i;
                source.second = j;
                found = true;
                break;
            }
        }
        if (found)
            break;
    }
    cout << source.first << " " << source.second << endl;
    vector<char> ans = findPosition(source, mat);
    if (ans.empty()) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;

    for (auto &c : ans)
        cout << c << " ";
    cout << endl;
}
int main() {
    int t = 1;
    while (t--) {
        solve();
    }
}
