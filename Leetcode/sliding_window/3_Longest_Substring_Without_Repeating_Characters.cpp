#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> mpp;

    int l = 0;
    int len = 0;
    for (int r = 0; r < s.size(); r++) {
      if (mpp.count(s[r])) {
        l = max(l, mpp[s[r]] + 1);
      }
      len = max(len, r - l + 1);

      mpp[s[r]] = r;
    }
    return len;
  }
};
