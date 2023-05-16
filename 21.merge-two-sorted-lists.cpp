/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode sentinel(0);
    auto curr = &sentinel;
    while (list1 || list2) {
      if (!list1 || (list2 && list2->val < list1->val)) {
        curr->next = list2;
        list2 = list2->next;
      } else {
        curr->next = list1;
        list1 = list1->next;
      }
      curr = curr->next;
    }
    return sentinel.next;
  }
};
// @lc code=end
