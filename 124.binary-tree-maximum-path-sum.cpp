/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  int maxPathSum(TreeNode* root) {
    int sum = INT_MIN;
    helper(root, sum);
    return sum;
  }

  int helper(TreeNode* node, int& sum) {
    if (!node) {
      return 0;
    }
    int l = helper(node->left, sum);
    int r = helper(node->right, sum);
    sum = max(sum, l + r + node->val);
    return max(0, max(l, r) + node->val);
  }
};
// @lc code=end
