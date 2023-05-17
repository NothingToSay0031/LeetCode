/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int ncol = matrix[0].size(), nrow = matrix.size();
    int left = 0, right = ncol * nrow - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      int val = matrix[mid / ncol][mid % ncol];
      if (val > target) {
        right = mid - 1;
      } else if (val < target) {
        left = mid + 1;
      } else {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
