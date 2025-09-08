// @leet start
#include <unordered_map>
#include <unordered_set>
class Solution
{
  public:
    bool containsDuplicate(vector<int> &nums)
    {
        // TODO: assert parameters

        // Have a hash set store all the seen numbers
        std::unordered_set<int> seen;

        for (int val : nums)
        {
            if (seen.find(val) != seen.end())
                return true;

            else
                seen.emplace(val);
        }

        return false;
    }
};
// @leet end
