/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution {
 public:
  int longestOnes(vector<int>& nums, int k) {
    int start = 0, max_len = 0, n_zero = 0;
    for (int end = 0; end < nums.size(); ++end) {
      if (nums[end] == 0) {
        if (n_zero >= k) {
          while (start <= end && n_zero >= k) {
            if (nums[start] == 0) {
              --n_zero;
            }
            ++start;
          }
        }
        ++n_zero;
      }
      max_len = max(max_len, end - start + 1);
    }
    return max_len;
  }
};
// @lc code=end
