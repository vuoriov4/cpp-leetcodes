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
    ListNode* swapPairs(ListNode* head) {
      ListNode* crt = new ListNode(0, head);
      if (head == nullptr) return nullptr;
      else if (head->next != nullptr) head = head->next;
      while(crt->next != nullptr && crt->next->next != nullptr) {
        cout << crt->val << endl;
        ListNode* first = crt->next;
        ListNode* second = crt->next->next;
        first->next = second->next;
        second->next = first;
        crt->next = second;
        crt = crt->next->next;
      }
      return head;
    }
  };
