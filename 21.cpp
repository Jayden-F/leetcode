
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {

    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    ListNode *node;

    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val < list2->val) {
        node = new ListNode(list1->val);
        list1 = list1->next;
      } else {
        node = new ListNode(list2->val);
        list2 = list2->next;
      }

      if (head == nullptr && tail == nullptr) {
        head = tail = node;
      } else {
        tail->next = node;
        tail = node;
      }
    }

    while (list1 != nullptr) {
      node = new ListNode(list1->val);
      if (head == nullptr && tail == nullptr) {
        head = tail = node;
      } else {
        tail->next = node;
        tail = node;
      }
        list1 = list1->next;
    }

    while (list2 != nullptr) {
      node = new ListNode(list2->val);
      if (head == nullptr && tail == nullptr) {
        head = tail = node;
      } else {
        tail->next = node;
        tail = node;
      }
        list2 = list2->next;
    }

    return head;
  }
};
