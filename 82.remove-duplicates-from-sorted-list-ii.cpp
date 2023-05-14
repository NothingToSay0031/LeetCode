/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode sentinel(0, head);
    auto prev = &sentinel, curr = head;
    while (curr) {
      if (curr->next && curr->next->val == curr->val) {
        // 如果当前节点和下一个节点值相同
        while (curr->next && curr->next->val == curr->val) {
          curr = curr->next;
        }
        // 将当前节点移动到不同值的节点上，并修改前驱节点的next指针
        curr = curr->next;
        prev->next = curr;
      } else {
        // 如果当前节点和下一个节点值不同，则继续往后遍历
        prev = curr;
        curr = curr->next;
      }
    }
    return sentinel.next;
  }
};
// @lc code=end
