/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <unordered_set>
class Solution
{
  public:
    int numComponents(ListNode *head, vector<int> &nums)
    {

        // Store the numbers in nums into a hash set so that we can have an o(1) check
        std::unordered_set<int> nums_set;
        for (int num : nums)
        {
            nums_set.emplace(num);
        }

        // Have a pointer traverse the linked list to check for constructiveness
        ListNode *current = head;

        // The number of consquetive nums
        int consequetive = 0;
        bool isconsequative = false;

        while (current)
        {
            // Logic if the last element was in nums thus was constructive
            if (isconsequative)
            {
                if (nums_set.find(current->val) == nums_set.end())
                    isconsequative = false;
            }
            else
            {
                if (nums_set.find(current->val) != nums_set.end())
                {
                    ++consequetive;
                    isconsequative = true;
                }
            }
            current = current->next;
        }

        return consequetive;
    }
};
