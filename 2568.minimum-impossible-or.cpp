// @leet start
#include <unordered_set>
#include <vector>

using std::vector;

class Solution
{
  public:
    long minImpossibleOR(vector<int> &nums)
    {
        // Store all the numbers in nums is a hash map
        std::unordered_set<int> seen(nums.begin(), nums.end());

        unsigned long long i = 1;
        while (true)
        {
            if (seen.find(i) == seen.end())
                return i;

            i <<= 1;
        }
    }
};
// @leet end
