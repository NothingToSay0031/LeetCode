/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (target == nums[mid]) {
        return mid;
      } else if (target >= nums[left] && target < nums[mid] ||
                 (nums[mid] <= nums[right] &&
                  (target < nums[mid] || target > nums[right]))) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return -1;
  }
};
// @lc code=end
