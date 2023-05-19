/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    for (int i = 0; i < points.size(); ++i) {
      pq.push({-pow(points[i][0], 2) - pow(points[i][1], 2), i});
    }
    vector<vector<int>> res;
    for (int i = 0; i < k; ++i) {
      res.push_back(points[pq.top().second]);
      pq.pop();
    }
    return res;
  }
};
// @lc code=end
