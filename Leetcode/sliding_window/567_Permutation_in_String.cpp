
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size())
      return false;
    unordered_map<char, int> mpp, cpp;

    for (int i = 0; i < s1.size(); i++) {
      mpp[s1[i]]++;
      cpp[s2[i]]++;
    }

    if (mpp == cpp)
      return true;
    int l = 0;
    for (int r = s1.size(); r < s2.size(); r++) {
      cpp[s2[r]]++;
      cpp[s2[l]]--;

      if (cpp[s2[l]] == 0)
        cpp.erase(s2[l]);

      l++;
      if (mpp == cpp)
        return true;
    }
    return false;
  }
};
// int main() {
//   string s1 = "ab";
//   string s2 = "eidbaooo";

//   Solution s;

//   if (s.checkInclusion(s1, s2))
//     cout << "true" << endl;
//   else
//     cout << "false";
// }
