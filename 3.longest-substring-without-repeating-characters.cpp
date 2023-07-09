/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int start = 0, end = 0, max_len = 0;
    while (end < s.size()) {
      while (set.count(s[end])) {
        set.erase(s[start]);
        ++start;
      }
      set.insert(s[end]);
      ++end;
      max_len = max(max_len, end - start);
    }
    return max_len;
  }
};
// @lc code=end
