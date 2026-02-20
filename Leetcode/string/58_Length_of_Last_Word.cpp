#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    string token;
    stringstream ss(s);
    while (ss >> token) {
    }
    cout << token << endl;

    return token.size();
  }
};
int main() {
  string s = "   fly me   to   the moon  ";
  Solution sol;

  cout << sol.lengthOfLastWord(s) << endl;
}
