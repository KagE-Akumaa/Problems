

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int getWinner(vector<int> &ast, vector<int> &ans, int i) {
    int winner = 0;

    while (!ans.empty()) {

      if ((ans.back() > 0 && ast[i] > 0) || (ans.back() < 0 && ast[i] < 0)) {
        break;
      }

      if (ans.back() < 0 && ast[i] > 0) {
        break;
      }

      if (abs(ans.back()) < abs(ast[i])) {
        winner = ast[i];
        ans.pop_back();
        continue;
      } else if (abs(ans.back()) > abs(ast[i])) {
        winner = 0;
        break;
      } else {
        ans.pop_back();
        winner = 0;
        break;
      }
    }
    cout << winner << endl;
    return winner;
  }

  vector<int> asteroidCollision(vector<int> &asteroids) {
    vector<int> ans;

    for (int i = 0; i < asteroids.size(); i++) {

      if (ans.empty()) {
        ans.push_back(asteroids[i]);
        continue;
      }

      if (!ans.empty() && asteroids[i] > 0 && ans.back() > 0) {
        ans.push_back(asteroids[i]);
        continue;
      }
      if (!ans.empty() && asteroids[i] < 0 && ans.back() < 0) {
        ans.push_back(asteroids[i]);
        continue;
      }

      if (!ans.empty() && ans.back() < 0 && asteroids[i] > 0) {
        ans.push_back(asteroids[i]);
        continue;
      }

      int winner = getWinner(asteroids, ans, i);
      if (winner != 0) {
        ans.push_back(winner);
      }
    }

    return ans;
  }
};

int main() {
  vector<int> asteroids = {1, -1, -2, -2};
  Solution s;

  vector<int> ans = s.asteroidCollision(asteroids);

  for (auto &i : ans)
    cout << i << " ";
  cout << endl;
}
