/**
 * Definition for singly-linked list.
 * struct ListNode {
 *   int val;
 *   ListNode *next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* oddEvenList(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode* odd = head; 
    if (head->next == nullptr) return head;
    ListNode* even = head->next;
    while (even != nullptr) {
      ListNode* current = even->next;
      if (current == nullptr) break;
      cut(even, current, odd);
      even = even->next;
      odd = current;
    }
    return head; 
  }
  void cut(ListNode* x_prev, ListNode* x, ListNode* y) {
    x_prev->next = x->next;
    x->next = y->next;
    y->next = x;
  }
};
