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
#include <atomic>
#include <clocale>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
class Solution
{
  public:
    //   struct TreeNodeHash
    //   {
    //       size_t operator()(const TreeNode *node) const
    //       {
    //           std::hash<std::string> hasher;
    //           if (not node)
    //           {
    //               return hasher("NULL");
    //           }
    //           std::string node_string = std::to_string(node->val) + "," +
    //                                     (node->left ? std::to_string(node->left->val) : "NULL") +
    //                                     "," +
    //                                     (node->right ? std::to_string(node->right->val) :
    //                                     "NULL");
    //           return hasher(node_string);
    //       };
    //   };
    //   std::vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    //   {
    //       std::unordered_set<TreeNode *> seen = std::unordered_set<TreeNode *, TreeNodeHash>();
    //       std::unordered_set<TreeNode *> duplicates = std::unordered_set<TreeNode *,
    //       TreeNodeHash>(); findDuplicateSubtrees_helper(root, seen, duplicates);
    //
    //       std::vector<TreeNode *> answer;
    //       for (TreeNode *node : duplicates)
    //       {
    //           answer.push_back(node);
    //       }
    //
    //       return answer;
    //   }
    //
    // private:
    //   void findDuplicateSubtrees_helper(TreeNode *root,
    //                                     std::unordered_set<TreeNode *, TreeNodeHash> &seen,
    //                                     std::unordered_set<TreeNode *, TreeNodeHash> &duplicates)
    //   {
    //
    //       if (seen.find(root) != seen.end())
    //       {
    //           // This node has been seen before, so we have a duplicate subtree
    //           // add it to the duplicates
    //           duplicates.insert(root);
    //       }
    //       else
    //       {
    //           seen.insert(root);
    //       }
    //
    //       findDuplicateSubtrees_helper(root->left, seen, duplicates);
    //       findDuplicateSubtrees_helper(root->right, seen, duplicates);
    //   }
    std::vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        // Store each subtree inside the hashmap with the number of times it has been seen
        std::unordered_map<std::string, int> seen;
        std::vector<TreeNode *> answer;
        searialize_and_find(root, seen, answer);
        return answer;
    }

  private:
    std::string searialize_and_find(TreeNode *root, std::unordered_map<std::string, int> &seen,
                                    std::vector<TreeNode *> &answer)
    {
        if (not root)
        {
            return "#";
        }

        std::string serial = std::to_string(root->val) + "," +
                             searialize_and_find(root->left, seen, answer) + "," +
                             searialize_and_find(root->right, seen, answer);

        // Increment the count of this subtree in the seen map
        seen[serial] += 1;

        // if this subtree has been seen twice, add it to the answer list
        if (seen[serial] == 2)
        {
            answer.push_back(root);
        }
        return serial;
    }
};
// @leet end
