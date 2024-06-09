struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) { }
    ListNode(int x) : val(x), next(nullptr) { }
    ListNode(int x, ListNode* next) : val(x), next(next) { }
};

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) { }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right)
    { }
};
class Solution
{
  public:
    TreeNode*
    sortedListToBST(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* right = sortedListToBST(slow);
        slow->next = nullptr;
        TreeNode* left = sortedListToBST(head);

        return new TreeNode(slow->val, left, right);
    }
};
