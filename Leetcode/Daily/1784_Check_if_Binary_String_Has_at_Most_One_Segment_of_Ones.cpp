#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool checkOnesSegment(string s) {
    if (s.empty())
      return false;
    int count = 0;
    for (auto &it : s) {
      if (it == '1')
        count++;
    }
    if (count == 1)
      return true;
    if (count == 0)
      return false;

    int c = 0, nc = 0;
    for (int i = 0; i < s.size() - 1; i++) {
      if ((s[i] == '1') && (s[i] == s[i + 1]))
        c++;
      else {
        if (c > 0) {
          nc++;
          c = 0;
        }
      }
    }

    return nc == 1 ? true : false;
  }
};
