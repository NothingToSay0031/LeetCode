/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
// @lc code=start
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
      int elem = nums[i];
      if (map.count(target - elem)) {
        return {map[target - elem], i};
      } else {
        map[elem] = i;
      }
    }
    return {};
  }
};
// @lc code=end
