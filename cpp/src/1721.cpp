#include <cstddef>

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
    swapNodes(ListNode* head, int k)
    {
        ListNode* left = head;
        for(size_t i = 1; i < k; i++)
        {
            left = left->next;
        }

        ListNode* right = head;
        ListNode* fast = left;
        while(fast->next != nullptr)
        {
            right = right->next;
            fast = fast->next;
        }

        int temp = left->val;
        left->val = right->val;
        right->val = temp;

        return head;
    }
};
