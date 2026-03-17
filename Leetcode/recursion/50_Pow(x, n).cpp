#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  double power(double x, int n) {
    if (n == 0)
      return 1;
    double sub = power(x, n / 2);
    double subsq = sub * sub;

    if (n & 1) {
      return x * subsq;
    } else {
      return subsq;
    }
  }
  double myPow(double x, int n) {
    if (n == 0) {
      return 1;
    }
    if (n < 0) {
      x = 1 / x;
    }
    return power(x, n);
  }
};
