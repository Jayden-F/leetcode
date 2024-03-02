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
  void inorder(TreeNode *root, vector<int> &result) {

    if (root == nullptr) {
      return;
    }

    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
  }

  vector<int> inorderTraversal(TreeNode *root) {

    vector<int> result;
    inorder(root, result);
    return result;
  }

  vector<int> iterativeInorderTraversal(TreeNode* root) {

        vector<TreeNode*> stack;
        vector<int> result;
        TreeNode* curr = root;

        while (curr != nullptr || !stack.empty()) {
            while (curr != nullptr) {
                stack.push_back(curr);
                curr = curr->left;
            }

            curr = stack.back();
            stack.pop_back();
            result.push_back(curr->val);

            curr = curr->right;
        }

        return result;
    }

};
