#include <vector>

using std::vector;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *buildTree(vector<int> &nums, size_t low, size_t high) {

    if (low >= high) {
      return nullptr;
    }

    size_t mid = low + (high - low) / 2;
    TreeNode *parent = new TreeNode(nums[mid]);

    parent->left = buildTree(nums, low, mid);
    parent->right = buildTree(nums, mid + 1, high);

    return parent;
  }

  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return buildTree(nums, 0, nums.size());
  }
};
