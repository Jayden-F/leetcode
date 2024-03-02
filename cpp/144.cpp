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
  void preorder(TreeNode *root, vector<int> &result) {

    if (root == nullptr) {
      return;
    }

    result.push_back(root->val);
    preorder(root->left, result);
    preorder(root->right, result);
  }

  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> result;
    preorder(root, result);
    return result;
  }

  vector<int> iteraivePreorderTraversal(TreeNode *root) {

    vector<TreeNode *> stack;
    vector<int> result;

    stack.push_back(root);

    while (!stack.empty()) {

      TreeNode *curr = stack.back();
      stack.pop_back();

      if (curr == nullptr) {
        continue;
      }
      result.push_back(curr->val);

      stack.push_back(curr->right);
      stack.push_back(curr->left);
    }

    return result;
  }
};
