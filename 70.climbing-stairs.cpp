/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
 public:
  int climbStairs(int n) {
    std::vector<int> steps(n + 1);
    steps[0] = 1, steps[1] = 1;
    for (int i = 2; i <= n; ++i) {
      steps[i] = steps[i - 1] + steps[i - 2];
    }
    return steps[n];
  }
};
// @lc code=end
