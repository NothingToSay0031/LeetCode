/*
 * @lc app=leetcode id=1249 lang=cpp
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

// @lc code=start
class Solution {
 public:
  string minRemoveToMakeValid(string s) {
    std::stack<int> pos;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '(') {
        pos.push(i);
      } else if (s[i] == ')') {
        if (!pos.empty()) {
          pos.pop();
        } else {
          s[i] = '*';
        }
      }
    }
    while (!pos.empty()) {
      s[pos.top()] = '*';
      pos.pop();
    }
    s.erase(remove(s.begin(), s.end(), '*'), s.end());
    return s;
  }
};
// @lc code=end
