/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = accumulate(begin(nums), end(nums), 0);
    int target = sum / 2;
    if (sum & 1) {
      return false;
    }
    bitset<10001> dp(1);
    for (const auto n : nums) {
      dp |= dp << n;
    }
    return dp[target];
  }
};
// @lc code=end
