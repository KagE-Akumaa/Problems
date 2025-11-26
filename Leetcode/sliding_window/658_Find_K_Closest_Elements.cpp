#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> findClosestElements(vector<int> &arr, int k, int x) {
    auto cmp = [](pair<int, int> a, pair<int, int> b) -> bool {
      if (a.second == b.second)
        return a.first < b.first;
      return a.second < b.second;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(
        cmp);

    for (int i = 0; i < arr.size(); i++) {
      int diff = abs(arr[i] - x);
      pq.push({arr[i], diff});
    }
    vector<int> ans;
    while (!pq.empty()) {
      cout << pq.top().first << " ";
      ans.push_back(pq.top().first);
      pq.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};
