/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int left = matrix[0][0], right = matrix[n - 1][n - 1];
    while (left <= right) {
      int mid = (left + right) / 2;
      int cnt = 0, i = n - 1, j = 0;
      while (i >= 0 && j < n) {
        if (matrix[i][j] > mid) {
          --i;
        } else {
          cnt += i + 1;
          ++j;
        }
      }
      if (k <= cnt) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return left;
  }
};
// @lc code=end
