/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
 public:
  bool isValid(string s) {
    unordered_map<char, char> map = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
    stack<char> stack;
    for (const auto c : s) {
      if (map.count(c)) {
        stack.push(c);
      } else if (stack.size() && map[stack.top()] == c) {
        stack.pop();
      } else {
        return false;
      }
    }
    return stack.size() == 0;
  }
};
// @lc code=end
