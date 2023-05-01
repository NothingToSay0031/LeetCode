/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
 public:
  bool isAnagram(string s, string t) {
    std::unordered_map<char, int> cnt;
    if (s.size() != t.size()) {
        return false;
    }
    for (const auto c : s) {
      ++cnt[c];
    }
    for (const auto c : t) {
      --cnt[c];
    }
    for (const auto [k, v] : cnt) {
      if (v != 0) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
