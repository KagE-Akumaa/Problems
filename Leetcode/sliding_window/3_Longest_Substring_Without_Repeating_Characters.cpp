#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    vector<char> mpp(256, 0);
    int l = 0, len = 0;
    for (int r = 0; r < s.size(); r++) {
      mpp[s[r]]++;
      while (mpp[s[r]] > 1) {
        mpp[s[l]]--;
        l++;
      }
      len = max(len, r - l + 1);
    }
    return len;
  }
};

int main() {
  string s = "abcabcbb";
  Solution sol;

  cout << sol.lengthOfLongestSubstring(s) << endl;
}
