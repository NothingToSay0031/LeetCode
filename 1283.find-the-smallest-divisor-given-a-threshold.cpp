/*
 * @lc app=leetcode id=1283 lang=cpp
 *
 * [1283] Find the Smallest Divisor Given a Threshold
 */

// @lc code=start
class Solution {
 public:
  int smallestDivisor(vector<int>& nums, int threshold) {
    int left = 1, right = *max_element(nums.begin(), nums.end());
    while (left <= right) {
      int mid = (left + right) / 2;
      int sum = 0;
      for (const auto n : nums) {
        sum += (n + mid - 1) / mid;
      }
      if (sum <= threshold) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};
// @lc code=end
