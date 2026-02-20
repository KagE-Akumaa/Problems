#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> res(n);
  for (int &i: res)
  cin >> i;

  for (auto &it: res)
  {
    cout << it << endl;
  }
}