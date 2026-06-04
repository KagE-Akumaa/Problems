#include <bits/stdc++.h>
using namespace std;

class Solution {
      public:
        int maxProduct(int n) {
#if 0
                // NOTE: Brute Force T.C - O(n log(n)) Space - O(n)

                vector<int> res;

                while (n > 0) {
                        res.push_back(n % 10);

                        n = n / 10;
                }

                sort(res.begin(), res.end());

                int a = res[res.size() - 1], b = res[res.size() - 2];

                return a * b;
#endif

                // NOTE: T.C - O(n) and space O(1)
                int firstLargest = 0, secondL = 0;

                while (n > 0) {

                        int rem = n % 10;

                        if (rem >= firstLargest) {
                                secondL = firstLargest;
                                firstLargest = rem;
                        } else if (rem < firstLargest && rem > secondL) {
                                secondL = rem;
                        }
                        n = n / 10;
                }

                return firstLargest * secondL;
        }
};
