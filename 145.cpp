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
  void recursivePostorderTraversal(TreeNode *root, vector<int> &results) {

    if (root == nullptr) {
      return;
    }
    recursivePostorderTraversal(root->left, results);
    recursivePostorderTraversal(root->right, results);
    results.push_back(root->val);
  }

  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    vector<TreeNode *> stack;

    while (!stack.empty()) {
        TreeNode *current = stack.back();

        while( current != nullptr) {
            stack.push_back(current->left);
        }

    }

    return res;
  }
};
