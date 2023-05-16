/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto cmp = [](ListNode* lhs, ListNode* rhs) { return lhs->val > rhs->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
    for (const auto list : lists) {
      if (list) {
        pq.push(list);
      }
    }
    ListNode sentinel(0);
    auto merged = &sentinel;
    while (pq.size()) {
      auto min = pq.top();
      pq.pop();
      merged->next = min;
      merged = merged->next;
      if (min->next) {
        pq.push(min->next);
      }
    }
    return sentinel.next;
  }
};
// @lc code=end
