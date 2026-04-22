
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isAlienSorted(vector<string> &words, string order) {
        if (words.empty() || words.size() < 2)
            return true;
        unordered_map<char, int> mpp;

        auto check = [&](string st, string str) -> bool {
            int i = 0, j = 0;

            while (i < st.size() && j < str.size()) {
                cout << mpp[st[i]] << " " << mpp[str[j]] << endl;
                if (mpp[st[i]] == mpp[str[j]]) {
                    i++;
                    j++;
                    continue;
                }
                if (mpp[st[i]] > mpp[str[j]]) {
                    return false;
                } else
                    return true;
            }
            if (st.size() <= str.size()) {
                return true;
            }
            return false;
        };
        for (int i = 0; i < order.size(); i++) {
            mpp[order[i]] = i;
        }
        for (int i = 1; i < words.size(); i++) {
            string first = words[i - 1];

            string second = words[i];

            if (!check(first, second)) {
                return false;
            }
        }
        return true;
    }
};
