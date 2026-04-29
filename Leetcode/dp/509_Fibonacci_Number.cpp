#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int check(int n, vector<int> &arr) {
        if (n == 0 || n == 1) {
            return n;
        }
        if (arr[n] != -1) {
            // NOTE: This means we have calculated this before
            return arr[n];
        }
        return arr[n] = check(n - 1, arr) + check(n - 2, arr);
    }
    int fib(int n) {

        if (n == 0 || n == 1)
            return n;
#if 0
        //NOTE: USING MEMOIZATION 

        vector<int> arr(n + 1, -1);
        return check(n, arr);
#endif
#if 0
        // NOTE: USING TABLE

        vector<int> f(n + 1, 0);
        f[0] = 0;
        f[1] = 1;

        for (int i = 2; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
#endif
        // NOTE: USING NO EXTRA SPACE

        int a = 0;
        int b = 1;
        int c = 0;

        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
