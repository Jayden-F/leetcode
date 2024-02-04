
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {

    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode *curr = head;
    ListNode *next = curr->next;

    while (next != nullptr) {
      if (curr->val != next->val) {
        curr->next = next;
        curr = next;
      }
      next = next->next;
    }
    curr->next = nullptr;
    return head;
  }
};
