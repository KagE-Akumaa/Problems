#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    void helper(vector<string> &ans, string &temp, string &digits, int start,
                unordered_map<char, string> &mpp) {
        // base case
        if (start == digits.size()) {
            ans.push_back(temp);
            return;
        }
        auto it = mpp[digits[start]];

        for (int i = 0; i < it.size(); i++) {
            temp.push_back(it[i]);
            helper(ans, temp, digits, start + 1, mpp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mpp{
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        string temp;
        vector<string> ans;

        helper(ans, temp, digits, 0, mpp);
        return ans;
    }
};
