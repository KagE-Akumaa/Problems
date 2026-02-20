#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  stringstream ss(s);
  s = "";
  string token;
  while (getline(ss, token, '+')) {
    s += token;
  }
  sort(s.begin(), s.end());

  for (int i = 0; i < s.size(); i++) {
    cout << s[i];
    if (i == s.size() - 1)
      break;
    cout << "+";
  }
}
