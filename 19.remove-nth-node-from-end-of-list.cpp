/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode sentinel(0, head);
    auto fast = &sentinel, slow = &sentinel;
    for (int i = 0; i <= n; ++i) {
      fast = fast->next;
    }
    while (fast) {
      slow = slow->next;
      fast = fast->next;
    }
    auto tmp = slow->next;
    slow->next = slow->next->next;
    delete tmp;
    return sentinel.next;
  }
};

// ListNode* removeNthFromEnd(ListNode* head, int n) {
//   unordered_map<int, ListNode*> map;
//   auto curr = head;
//   int len = 0;
//   while (curr) {
//     map[len] = curr;
//     ++len;  // off-by-one
//     curr = curr->next;
//   }
//   int index = len - n;
//   if (index == 0) {
//     head = head->next;
//   } else {
//     auto prev = map[index - 1];
//     prev->next = prev->next->next;
//   }
//   delete map[index];
//   return head;
// }

// @lc code=end
