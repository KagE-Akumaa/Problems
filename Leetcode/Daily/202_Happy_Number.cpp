#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isHappy(int n) {
        //
        if (n == 1)
            return true;
        unordered_set<int> st;

        while (true) {
            int newNumber = 0;
            while (n) {
                int rem = n % 10;
                n = n / 10;

                newNumber += pow(rem, 2);
            }
            if (newNumber == 1) {
                return true;
            }
            if (st.find(newNumber) != st.end()) {
                return false;
            }
            st.insert(newNumber);
        }

        return false;
    }
};
