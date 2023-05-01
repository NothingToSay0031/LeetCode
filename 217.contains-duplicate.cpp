/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    std::unordered_set<int> visited;
    for (const auto n : nums) {
      if (visited.count(n)) {
        return true;
      }
      visited.insert(n);
    }
    return false;
  }
};
// @lc code=end
