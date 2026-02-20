#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {
    unordered_map<char, int> mpp;
    int l = 0, len = 0, maxFreq = 0;

    for (int r = 0; r < s.size(); r++) {
      mpp[s[r]]++;

      maxFreq = max(maxFreq, mpp[s[r]]);

      if ((r - l + 1) - maxFreq > k) {
        mpp[s[l]]--;
        l++;
      }
      len = max(len, r - l + 1);
    }
    return len;
  }
};

int main() {
  string s = "AABABBA";
  int k = 1;
  Solution sol;
  cout << sol.characterReplacement(s, k) << endl;
}
