/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
 public:
  string minWindow(string s, string t) {
    vector<int> match(128, 0);
    for (const auto c : t) {
      ++match[c];
    }
    int remain = t.size(), left = 0, right = 0;
    int st = -1, len = INT_MAX;
    while (right < s.size()) {
      if (match[s[right++]]-- > 0) {
        --remain;
      }
      while (remain == 0) {
        if (len > right - left) {
          st = left;
          len = right - left;
        }
        if (match[s[left++]]++ == 0) {
          ++remain;
        }
      }
    }
    return st == -1 ? "" : s.substr(st, len);
  }
};
// @lc code=end
