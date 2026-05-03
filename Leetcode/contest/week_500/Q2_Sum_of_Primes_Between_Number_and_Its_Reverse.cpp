#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<bool> primes;
    bool already = false;

    void genPrimes() {
        if (already)
            return;

        int n = 10000;
        primes = vector<bool>(n + 1, true);

        primes[0] = false;
        primes[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (primes[i]) {
                for (int j = i * i; j <= n; j += i) {
                    primes[j] = false;
                }
            }
        }

        already = true;
    }
    void print(vector<bool> &primes) {
        for (int i = 0; i < primes.size(); i++) {
            cout << i << " " << primes[i] << endl;
        }
        cout << endl;
    }
    int sumOfPrimesInRange(int n) {
        genPrimes();
        int val1 = n;

        int temp = n;
        int rev = 0;
        while (temp > 0) {
            int rem = temp % 10;
            rev = rev * 10 + rem;
            temp = temp / 10;
        }

        cout << rev << endl;
        int l, r;

        l = min(val1, rev);
        r = max(val1, rev);
        cout << l << endl;
        cout << r << endl;
        int sum = 0;

        //    print(primes);
        for (int i = l; i <= r; i++) {
            if (primes[i]) {
                sum = sum + i;
            }
        }
        return sum;
    }
};

int main() {
    int n = 13;
    Solution s;
    cout << s.sumOfPrimesInRange(n) << endl;
}
