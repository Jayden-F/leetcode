struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeNodes(ListNode *head) {
    ListNode *left = head;
    ListNode *right = left->next;
    int total_sum = 0;

    while (right != nullptr) {
      if (right->val == 0) {
        right->val = total_sum;
        left->next = right;
        left = right;
        total_sum = 0;
        right = right->next;
      } else {
        total_sum += right->val;

        // update right and delete previous node.
        ListNode *temp = right;
        right = right->next;
        delete temp;
      }
    }
    ListNode *retval = head->next;
    delete head;
    return retval;
  }
};
