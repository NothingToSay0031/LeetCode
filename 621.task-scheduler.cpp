/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> count(26, 0);
    for (const auto task : tasks) {
      ++count[task - 'A'];
    }
    sort(count.begin(), count.end(), std::greater<int>());
    int max_cnt = count[0];
    int idle_slots = (max_cnt - 1) * n;
    for (int i = 1; i < 26; ++i) {
      idle_slots -= min(max_cnt - 1, count[i]);
    }
    return tasks.size() + max(idle_slots, 0);
  }
};
// @lc code=end
