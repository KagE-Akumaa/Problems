#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int calPoints(vector<string> &operations) {
    vector<int> ans;

    for (auto &ch : operations) {
      if (ch == "+") {
        int n = ans.size();
        ans.push_back(ans[n - 1] + ans[n - 2]);
      } else if (ch == "D") {
        if (!ans.empty()) {
          int val = ans.back();
          ans.push_back(2 * val);
        }
      } else if (ch == "C") {
        if (!ans.empty()) {
          ans.pop_back();
        }
      } else
        ans.push_back(stoi(ch));
    }

    int sum = accumulate(ans.begin(), ans.end(), 0);
    return sum;
  }
};

int main() {
  vector<string> s = {"5", "2", "C", "D", "+"};
  Solution sol;

  cout << sol.calPoints(s) << endl;
}
