// @leet start
#include <algorithm>
#include <cstdint>
#include <unordered_set>
class Solution
{
  public:
    int findMaxK(vector<int> &nums)
    {

        int max_num = INT32_MIN;
        // LOGIC: Create a hash set to store the seen numbers to check if a negative number exists
        std::unordered_set<int> seen;
        for (const int &i : nums)
        {
            if (seen.count(-i))
                max_num = std::max(std::abs(i), max_num);

            if (not seen.count(i))
                seen.insert(i);
        }

        return (max_num == INT32_MIN) ? -1 : max_num;
    }
};
// @leet end
