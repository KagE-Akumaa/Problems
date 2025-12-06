#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestKSubstr(string &s, int k) {
    unordered_map<char, int> mpp;
    int l = 0;
    int len = 0;
    for (int r = 0; r < s.size(); r++) {
      mpp[s[r]]++;
      while (mpp.size() > k) {
        // means window is invalid,
        mpp[s[l]]--;
        if (mpp[s[l]] == 0)
          mpp.erase(s[l]);
        l++;
      }
      if (mpp.size() == k) {
        len = max(len, r - l + 1);
      }
    }
    return len == 0 ? -1 : len;
  }
};
int main() {
  string s = "aabacbebebe";
  int k = 3;

  Solution sol;

  cout << sol.longestKSubstr(s, k) << endl;
}
