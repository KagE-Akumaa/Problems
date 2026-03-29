#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int firstMatchingIndex(string s) {
        unordered_map<int, int> mpp;

        int n = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == s[n - i - 1])
                return i;
        }
        return -1;
    }
};
