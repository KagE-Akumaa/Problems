#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> sortByBits(vector<int> &arr) {

    sort(arr.begin(), arr.end(), [](unsigned int a, unsigned int b) {
      int counta = __popcount(a);
      int countb = __popcount(b);

      return counta != countb ? counta < countb : a < b;
    });
    return arr;
  }
};
