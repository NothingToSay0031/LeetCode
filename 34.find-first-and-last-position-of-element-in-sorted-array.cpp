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
    while (left <= right) {
      int mid = (right + left) / 2;
      if (target > nums[mid]) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    if (left >= nums.size() || nums[left] != target) {
      return {-1, -1};
    }
    int start = left;
    right = nums.size() - 1;
    while (left <= right) {
      int mid = (right + left) / 2;
      if (target < nums[mid]) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return {start, right};
  }
};
// @lc code=end
