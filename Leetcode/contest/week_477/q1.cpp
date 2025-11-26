#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long sumAndMultiply(int n) {
    vector<long long> ans;
    while (n > 0) {
      int rem = n % 10;
      if (rem != 0)
        ans.push_back(rem);
      n = n / 10;
    }
    long long sum = accumulate(ans.begin(), ans.end(), 0);
    long long num = 0;
    long long p = 1;
    for (int i = 0; i < ans.size(); i++) {
      num = num + ans[i] * p;
      p = p * 10;
    }
    return num * sum;
  }
};
