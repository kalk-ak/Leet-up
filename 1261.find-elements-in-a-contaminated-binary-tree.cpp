// @leet start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <unordered_map>
#include <unordered_set>
class FindElements
{
  public:
    FindElements(TreeNode *root)
    {

        this->root = root;
        this->root->val = 0;
        populate(root, 0);
    }

    bool find(int target)
    {
        return value_set.count(target) > 0;
    }

  private:
    TreeNode *root;
    std::unordered_set<int> value_set = {0};

    void populate(TreeNode *root, int value)
    {

        int new_val; // the new value to be computed
        if (root->right)
        {
            new_val = value * 2 + 2;
            value_set.emplace(new_val); // Store the value in a hash map
            root->right->val = new_val;
            populate(root->right, new_val);
        }

        if (root->left)
        {
            new_val = value * 2 + 1;
            value_set.emplace(new_val);
            root->left->val = new_val;
            populate(root->left, new_val);
        }
    }

    bool dfs(TreeNode *root, int target)
    {
        if (not root)
            return false;

        if (root->val == target)
            return true;

        return (dfs(root->right, target) || dfs(root->left, target));
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// @leet end
