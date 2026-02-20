#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, s, x;
  cin >> n >> s >> x;
  int sum = 0;
  vector<int> res(n);
  for (int &i : res) {
    cin >> i;
    sum += i;
  }
  if (sum == s) {
    cout << "YES" << endl;
    return;
  }
  if (s < sum || (s - sum) % x != 0) {
    cout << "NO" << endl;
  } else
    cout << "YES" << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--)
    solve();
}
