// @leet start
#include <unordered_set>
class Solution
{
  public:
    int longestSquareStreak(vector<int> &nums)
    {

        std::sort(nums, nums.begin(), nums.end());

        // First: Add all the elements in nums into a set for o(1) check if number exists in future
        // access
        std::unordered_set<long long> nums_set;
        for (int num : nums)
        {
            nums_set.emplace(num);
        }

        size_t maxStreak = 1;
        for (long num : nums)
        {
            size_t streak = 1;

            unsigned long long square = num * num;

            while (nums_set.find(square) != nums_set.end())
            {
                ++streak;
                square *= square;
            }

            if (streak > maxStreak)
            {
                maxStreak = streak;
            }
        }
        return (maxStreak > 1) ? maxStreak : -1;
    }
};
// @leet end
