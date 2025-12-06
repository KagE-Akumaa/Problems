#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> decrypt(vector<int> &code, int k) {
    vector<int> b(code.size(), 0);
    if (k == 0)
      return b;

    int n = code.size();
    if (k > 0) {
      int sum = 0;
      for (int i = 1; i <= k; i++) {
        sum += code[i % n];
      }
      b[0] = sum;
      int idx = 0;
      for (int i = 1; i < n; i++) {
        sum -= code[i % n];
        sum += code[(i + k) % n];
        b[i] = sum;
      }
      return b;
    } else {
      k = abs(k);
      int sum = 0;
      for (int i = n - k; i < n; i++) {
        sum += code[i % n];
      }
      b[0] = sum;
      int start = n - k;
      for (int i = 1; i < n; i++) {
        sum -= code[start % n];
        sum += code[(start + k) % n];
        b[i] = sum;
        start++;
      }
      return b;
    }
  }
};
int main() {
  vector<int> code = {2, 4, 9, 3};
  int k = -2;
  Solution s;
  vector<int> ans = s.decrypt(code, k);
  for (auto it : ans)
    cout << it << " ";
}
