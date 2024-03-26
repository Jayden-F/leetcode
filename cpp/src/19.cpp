#include <cstddef>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {

    ListNode *front = head;
    ListNode *back = head;

    for (size_t i = 0; i < n; i++) {
      front = front->next;
      if (front == nullptr) {
        return head->next;
      }
    }

    while (front->next != nullptr) {
      front = front->next;
      back = back->next;
    }

    back->next = back->next->next;
    return head;
  }
};
