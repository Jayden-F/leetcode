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
  bool isSymmetricRec(TreeNode *left, TreeNode *right) {

    if (left == nullptr && right == nullptr) {
      return true;
    }

    if (left == nullptr || right == nullptr) {
      return false;
    }

    return left->val == right->val &&
           isSymmetricRec(left->left, right->right) &&
           isSymmetricRec(left->right, right->left);
  }

  bool isSymmetric(TreeNode *root) {

    if (root == nullptr)
      return true;

    return isSymmetricRec(root->left, root->right);
  }
};
