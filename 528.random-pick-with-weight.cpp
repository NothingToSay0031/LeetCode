/*
 * @lc app=leetcode id=528 lang=cpp
 *
 * [528] Random Pick with Weight
 */

// @lc code=start
class Solution {
 public:
  vector<int> prefix;
  Solution(vector<int>& w) : prefix(w.size()) {
    prefix[0] = w[0];
    for (int i = 1; i < w.size(); ++i) {
      prefix[i] = prefix[i - 1] + w[i];
    }
  }

  int pickIndex() {
    int random = rand() % prefix.back() + 1;
    auto iter = lower_bound(prefix.begin(), prefix.end(), random);
    return iter - prefix.begin();
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end
