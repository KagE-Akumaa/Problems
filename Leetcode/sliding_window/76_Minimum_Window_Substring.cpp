#include <bits/stdc++.h>
using namespace std;

struct Trip {
  int len = INT_MAX;
  int start = -1;
  int end = -1;
};
class Solution {
public:
  string minWindow(string s, string t) {
    if (t.size() > s.size())
      return "";
    unordered_map<char, int> mpp;
    for (char &ch : t)
      mpp[ch]++;
    Trip ans;
    int left = 0;
    int total = t.size();
    for (int right = 0; right < s.size(); right++) {
      mpp[s[right]]--;

      if (mpp[s[right]] >= 0)
        total--;

      while (!total && left <= right) {
        if (ans.len > (right - left + 1)) {
          ans.len = right - left + 1;
          ans.start = left;
          ans.end = right;
        }
        mpp[s[left]]++;
        if (mpp[s[left]] > 0) {
          total++;
        }
        left++;
      }
    }
    if (ans.start == -1 || ans.end == -1)
      return "";
    string val = "";
    for (int i = ans.start; i <= ans.end; i++) {
      val.push_back(s[i]);
    }
    return val;
  }
};
int main() {
  string s = "ADOBECODEBANC", t = "ABC";
  Solution sol;

  cout << sol.minWindow(s, t) << endl;
}
