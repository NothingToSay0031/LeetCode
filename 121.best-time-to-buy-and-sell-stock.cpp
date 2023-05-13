/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int minimum = prices[0];
    int profit = 0;
    for (const int price : prices) {
      profit = std::max(price - minimum, profit);
      minimum = std::min(minimum, price);
    }
    return profit;
  }
};
// @lc code=end
