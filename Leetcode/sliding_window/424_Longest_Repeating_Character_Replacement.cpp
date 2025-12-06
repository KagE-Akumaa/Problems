#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int characterReplacement(string s, int k) {

    if (k == 0) {
      int len = 1, j = 0;
      for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
          j = i + 1;
        }
        len = max(i - j + 1, len);
      }
      return len;
    }

    int i = 0, len = 1;
    int c = k;
    for (int j = 1; j < s.size(); j++) {
      if (s[j] != s[j - 1]) {
        if (c != 0) {
          // then we can change in
          s[j] = s[j - 1];
          c--;
        } else {
          i = j;
          c = k;
        }
      }
      len = max(len, j - i + 1);
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
