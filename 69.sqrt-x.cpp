/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
 public:
  int mySqrt(int num) {
    if (num == 0) {
      return num;
    }
    int root = num;
    while (root > num / root) {
      root = (static_cast<long>(root) + num / root) / 2;
    }
    return root;
  }
};

// int left = 1, right = x;
// while (left <= right) {
//   int mid = left + (right - left) / 2;
//   if (mid < x / mid) {
//     left = mid + 1;
//   } else if (mid > x / mid) {
//     right = mid - 1;
//   } else {
//     return mid;
//   }
// }
// return right;

// @lc code=end
