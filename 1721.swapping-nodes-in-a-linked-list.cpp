/*
 * @lc app=leetcode id=1721 lang=cpp
 *
 * [1721] Swapping Nodes in a Linked List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* swapNodes(ListNode* head, int k) {
    ListNode dummy(0, head);
    auto left = &dummy, right = left;
    for (int i = 0; i < k; ++i) {
      left = left->next;
    }
    auto tmp = left;
    while (tmp) {
      tmp = tmp->next;
      right = right->next;
    }
    std::swap(left->val, right->val);
    return dummy.next;
  }
};
// @lc code=end
