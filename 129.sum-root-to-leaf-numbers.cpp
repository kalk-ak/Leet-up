// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  int sumNumbers(TreeNode *root) {
    int total_sum = 0;
    sumHelper(root->right, root->val, total_sum);
    sumHelper(root->left, root->val, total_sum);
    return total_sum;
  }

  void sumHelper(TreeNode *root, int sum, int &total_sum) {

    if (!root) {
      total_sum += sum;
      return;
    }

    sum += (sum * 10) + root->val;

    // call function recursively for both left and right child of tree
    sumHelper(root->right, sum, total_sum);
    sumHelper(root->left, sum, total_sum);
  }
};
// @leet end
