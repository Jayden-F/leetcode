struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    ListNode *current_1 = headA;
    ListNode *current_2 = headB;

    if (current_1 == nullptr || current_2 == nullptr) {
      return nullptr;
    }

    while (current_1 != current_2) {
      current_1 = current_1 != nullptr ? current_1->next : headB;
      current_2 = current_2 != nullptr ? current_2->next : headA;
    }
    return current_1;
  }
};
