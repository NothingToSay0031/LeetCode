/*
 * @lc app=leetcode id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */

// @lc code=start
class Solution {
 public:
  int maxScore(vector<int>& cardPoints, int k) {
    int front = 0, back = 0, curr;
    for (int i = 0; i < k; ++i) {
      front += cardPoints[i];
    }
    int max_score = front, n = cardPoints.size();
    for (int i = k - 1; i >= 0; --i) {
      front -= cardPoints[i];
      back += cardPoints[n - k + i];
      curr = front + back;
      max_score = std::max(max_score, curr);
    }
    return max_score;
  }
};
// @lc code=end
