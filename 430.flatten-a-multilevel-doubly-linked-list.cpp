/*
 * @lc app=leetcode id=430 lang=cpp
 *
 * [430] Flatten a Multilevel Doubly Linked List
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
 public:
  Node* flatten(Node* head) {
    auto curr = head;
    while (curr) {
      if (curr->child) {
        auto child_head = flatten(curr->child);
        auto nxt = curr->next;
        curr->next = child_head;
        child_head->prev = curr;
        curr->child = nullptr;

        while (curr->next) {
          curr = curr->next;
        }
        curr->next = nxt;
        if (nxt) {
          nxt->prev = curr;
        }
      } else {
        curr = curr->next;
      }
    }
    return head;
  }
};
// @lc code=end
