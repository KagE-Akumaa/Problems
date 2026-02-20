#include <bits/stdc++.h>
using namespace std;

// ahhellllloou
void solve() {
  string s;
  cin >> s;
  string ans = "hello";
  string str;

  if (s.size() < 5) {
    cout << "NO" << endl;
    return;
  }
  int j = 0;

  for (int i = 0; i < s.size(); i++) {

    if (j <= i && s[i] == ans[j]) {
      str += ans[j];
      j++;
    }
  }
  if (str == ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
int main() {
  int t = 1;
  while (t--)
    solve();
}
