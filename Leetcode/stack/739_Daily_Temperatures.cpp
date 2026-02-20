#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    vector<int> diff(temperatures.size(), 0);
    stack<int> st;
    for (int i = 0; i < temperatures.size(); i++) {
      while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
        diff[st.top()] = i - st.top();
        st.pop();
      }
      st.push(i);
    }
    return diff;
  }
};
