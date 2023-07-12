/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    if (s2.size() < s1.size()) {
      return false;
    }
    vector<int> match(26, 0);
    vector<int> count(26, 0);
    for (int i = 0; i < s1.size(); ++i) {
      ++match[s1[i] - 'a'];
      ++count[s2[i] - 'a'];
    }
    for (int i = s1.size(); i < s2.size(); ++i) {
      if (count == match) {
        return true;
      }
      ++count[s2[i] - 'a'];
      --count[s2[i - s1.size()] - 'a'];
    }
    return match == count;
  }
};
// @lc code=end
