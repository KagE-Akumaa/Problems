#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minSpeedOnTime(vector<int> &dist, double hour) {
    int l = 1;
    int r = 1e7;
    int ans = -1;
    auto check = [&](int m) -> bool {
      double h = 0;
      for (int i = 0; i < dist.size(); i++) {
        if (dist[i] % m == 0) {
          h += dist[i] / m;
        } else {
          if (i != dist.size() - 1) {
            h += (int)((double)dist[i] / m + 1);
          } else
            h += (double)dist[i] / m;
        }
      }
      return h <= hour;
    };
    while (l <= r) {
      int m = l + (r - l) / 2;

      if (check(m)) {
        ans = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return ans;
  }
};
int main() {
  vector<int> dist = {1, 3, 2};
  double hour = 6;

  Solution sol;

  cout << sol.minSpeedOnTime(dist, hour) << endl;
}
