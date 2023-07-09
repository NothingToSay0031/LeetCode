/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < abs(target) || (sum + target) % 2 == 1) {
      return 0;
    }
    return subsetSum(nums, (sum + target) / 2);
  }

  int subsetSum(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (const auto n : nums) {
      for (int i = target; i >= n; --i) {
        dp[i] += dp[i - n];
      }
    }
    return dp[target];
  }
};
// @lc code=end
