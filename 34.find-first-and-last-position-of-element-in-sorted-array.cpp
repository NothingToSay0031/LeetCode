/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
      int mid = (right + left) / 2;
      if (target > nums[mid]) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    if (right < 0 || nums[left] != target) {
      return {-1, -1};
    } else {
      int left_range = left;
      right = nums.size() - 1;
      while (left < right) {
        int mid = (right + left + 1) / 2;
        if (target < nums[mid]) {
          right = mid - 1;
        } else {
          left = mid;
        }
      }
      return {left_range, right};
    }
  }
};
// @lc code=end
