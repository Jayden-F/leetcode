#include <algorithm>
#include <cstdlib>

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
  int treeDepth(TreeNode *node) {

    if (node == nullptr) {
      return 0;
    }
    return std::max(treeDepth(node->left), treeDepth(node->right)) + 1;
  }

  bool isBalanced(TreeNode *root) {

    if (root == nullptr) {
      return true;
    }
    return abs(treeDepth(root->left) - treeDepth(root->right)) <= 1 &&
           isBalanced(root->left) && isBalanced(root->right);
  }
};
