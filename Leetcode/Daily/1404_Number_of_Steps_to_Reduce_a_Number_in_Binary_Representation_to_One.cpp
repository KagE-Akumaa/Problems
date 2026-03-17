#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int numSteps(string s) {
    int steps = 0, carry = 0;

    for (int i = s.size() - 1; i > 0; i--) {
      int bit = (s[i] - '0') + carry;

      if (bit == 0) {
        steps++;
        carry = 0;
      } else if (bit == 1) {
        steps += 2;
        carry = 1;
      } else {
        steps++;
        carry = 1;
      }
    }
    if (carry)
      steps++;
    return steps;
  }
};
