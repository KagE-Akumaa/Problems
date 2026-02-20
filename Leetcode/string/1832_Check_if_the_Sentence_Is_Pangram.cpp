#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  bool checkIfPangram(string sentence) {
#if 0
    unordered_set<char> s(sentence.begin(), sentence.end());
    return s.size() == 26;
#endif
    vector<bool> v(26, false);

    for (char &ch : sentence) {
      v[ch - 'a'] = true;
    }
    char ch = 'c';
    cout << ch - 'a' << endl;
    for (auto it : v) {
      if (!it)
        return false;
    }
    return true;
  }
};

int main() {
  string s = "hclllo";
  Solution sol;

  cout << sol.checkIfPangram(s) << endl;
}
