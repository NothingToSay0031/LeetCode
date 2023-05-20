/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution {
 public:
  string decodeString(string s) {
    stack<int> nums;
    stack<string> strs;
    int n = 0;
    string res = "";
    for (const auto c : s) {
      if (isdigit(c)) {
        n = n * 10 + c - '0';
      } else if (c == '[') {
        nums.push(n);
        strs.push(res);
        res = "";
        n = 0;
      } else if (c == ']') {
        string tmp = strs.top();
        strs.pop();
        int times = nums.top();
        nums.pop();
        for (int i = 0; i < times; ++i) {
          tmp += res;
        }
        res = move(tmp);
      } else {
        res += c;
      }
    }
    return res;
  }
};
// @lc code=end
