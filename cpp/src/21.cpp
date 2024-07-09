
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) { }
    ListNode(int x) : val(x), next(nullptr) { }
    ListNode(int x, ListNode* next) : val(x), next(next) { }
};

class Solution
{
  public:
    ListNode*
    mergeTwoLists(ListNode* list1, ListNode* list2)
    {

        ListNode* head = new ListNode();
        ListNode* tail = head;

        while(list1 != nullptr && list2 != nullptr)
        {
            int min_val;
            if(list1->val < list2->val)
            {
                min_val = list1->val;
                list1 = list1->next;
            }
            else
            {
                min_val = list2->val;
                list2 = list2->next;
            }
            tail->next = new ListNode(min_val);
            tail = tail->next;
        }

        if(list1 != nullptr) { tail->next = list1; }
        if(list2 != nullptr) { tail->next = list2; }

        return head->next;
    }
};
