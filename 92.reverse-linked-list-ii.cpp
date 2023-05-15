/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head || !head->next) {
      return head;
    }
    ListNode sentinel(0, head);
    ListNode* prev = &sentinel;
    for (int i = 0; i < left - 1; ++i) {  // 找到翻转起点的前一个节点
      prev = prev->next;
    }
    auto curr = prev->next;  // 初始化 curr 指针为翻转起点
    for (int i = left; i < right; ++i) {
      // 保存curr的下一个节点
      auto temp = curr->next;
      // curr->next指向temp的下一个节点，断开了temp节点与链表的连接
      curr->next = temp->next;
      // 将temp->next指向翻转区间之前节点的下一个节点
      temp->next = prev->next;
      // 完成插入操作
      prev->next = temp;
    }
    return sentinel.next;
  }
};
// @lc code=end
