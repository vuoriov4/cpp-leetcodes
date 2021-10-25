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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr && l2 == nullptr) return nullptr;
    ListNode* l3 = new ListNode();
    ListNode* l3_root = l3;
    ListNode* a = l1;
    ListNode* b = l2;
    while (a != nullptr || b != nullptr) {
      int x;
      if (a == nullptr) {
        x = b->val;
        b = b->next;
      }
      else if (b == nullptr) {
        x = a->val;
        a = a->next;
      }
      else if (a->val < b->val) {
        x = a->val;
        a = a->next;
      } else {
        x = b->val;
        b = b->next;
      }       
      l3->val = x;
      if (a != nullptr || b != nullptr) {
        l3->next = new ListNode();
        l3 = l3->next;
      }
    }      
    return l3_root;
  }
};
