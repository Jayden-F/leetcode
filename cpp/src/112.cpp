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
  bool hasPathSum(TreeNode *root, int targetSum) {

    if (root == nullptr) {
      return false;
    }

    int sum = targetSum - root->val;
    if (sum < 0) {
      return false;
    } else if (sum == 0 && root->left == nullptr && root->right == nullptr) {
      return true;
    } else {
      return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
  }
};
