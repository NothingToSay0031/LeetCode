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
    vector<bool> exhausted(lists.size(), false);
    ListNode sentinel(0);
    auto merged = &sentinel;
    int n = 0;
    while (n < lists.size()) {
      int curr_min = INT_MAX, index = -1;
      for (int i = 0; i < lists.size(); ++i) {
        if (exhausted[i]) {
          continue;
        } else if (!lists[i]) {
          exhausted[i] = true;
          ++n;
        } else {
          if (curr_min >= lists[i]->val) {
            curr_min = lists[i]->val;
            index = i;
          }
        }
      }
      if (index >= 0) {
        merged->next = lists[index];
        merged = merged->next;
        lists[index] = lists[index]->next;
      }
    }
    return sentinel.next;
  }
};
// @lc code=end
