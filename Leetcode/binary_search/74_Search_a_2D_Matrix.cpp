#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int getRow(vector<vector<int>> &mat, int target) {
    int l = 0, r = mat.size() - 1;
    int col = mat[0].size() - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (target >= mat[m][0] && target <= mat[m][col]) {
        return m;
      } else if (mat[m][0] < target)
        l = m + 1;
      else
        r = m - 1;
    }
    return -1;
  }
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int row = getRow(matrix, target);
    if (row == -1)
      return false;

    int l = 0, r = matrix[0].size() - 1;

    while (l <= r) {
      int m = l + (r - l) / 2;

      if (matrix[row][m] == target)
        return true;
      else if (matrix[row][m] < target)
        l = m + 1;
      else
        r = m - 1;
    }
    return false;
  }
};
