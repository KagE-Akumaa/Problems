#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void recurse(vector<char> &s, int i) {
    if (i >= s.size() / 2) {
      return;
    }
    swap(s[i], s[s.size() - 1 - i]);
    recurse(s, i + 1);
  }
  void reverseString(vector<char> &s) {
    // Simple 2 pointers
    /*
    int l = 0, r = s.size() - 1;
    while (l <= r) {
      swap(s[l], s[r]);
      l++;
      r--;
    }
    */
    // Using Recursion
    int i = 0;
    recurse(s, i);
  }
};
