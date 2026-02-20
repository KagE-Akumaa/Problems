#include <bits/stdc++.h>
using namespace std;
pair<int, int> getRval(vector<int> &res, int n) {
  vector<int> c = res;
  sort(c.begin(), c.end(), greater<int>());
  int idx = -1;
  int val = 0;
  int bi = -1;
  for (int i = 0; i < res.size(); i++) {
    if (res[i] != c[i]) {
      val = c[i];
      bi = i;
      break;
    }
  }
  if (val == 0)
    return {-1, -1};
  // find the val and return that indx

  for (int i = 0; i < res.size(); i++) {
    if (res[i] == val) {
      idx = i;
      break;
    }
  }
  return {idx, bi};
}
void solve() {
  int n;
  cin >> n;
  vector<int> res(n);
  for (int &i : res)
    cin >> i;

  // Find the next smaller value and inside that reverse the segment.
  int val = n;
  if (res[0] == n) {
    // look for the next smaller value special case need to add loop so that we
    // get the right next max if they are in decreasing order
    pair<int, int> idx = getRval(res, n);
    if (idx.first == -1) {
      // no need to reverse array is decreasing sorted
    } else {
      // reverse from res.begin() + 1 to idx;
      reverse(res.begin() + idx.second, res.begin() + idx.first + 1);
    }

  } else {
    // need to find the position of n and rev from 0 to n;
    int idx = 0;
    for (int i = 0; i < n; i++) {
      if (res[i] == n) {
        idx = i;
        break;
      }
    }
    reverse(res.begin(), res.begin() + idx + 1);
  }
  for (auto &it : res) {
    cout << it << " ";
  }
  cout << endl;
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
