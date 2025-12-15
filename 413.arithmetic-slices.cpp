// @leet start
#include <vector>
class Solution
{
  public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        // LOGIC: Whenever we add a number that continues the arithmetic sequence,
        // the number of arithmetic slices increases by the length of the current sequence minus 2.

        // Stores the number of arithmetic subarrays until the nth index
        int length = nums.size();
        std::vector<int> arithmetic_subarray(length, 0);

        int last_break = 0;
        for (size_t i = 2; i < length; i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                arithmetic_subarray[i] = arithmetic_subarray[i - 1] + (i - last_break - 1);
            }
            else
            {
                arithmetic_subarray[i] = 0;
                last_break = i - 1;
            }
        }

        // Count the total number of subarrays that are arithmetic
        int total_count = 0;
        last_break = 0;
        for (size_t i = 2; i < length; i++)
        {
            if (arithmetic_subarray[i] != 0)
            {
                continue;
            }
            else
            {
                last_break = i;
                total_count += arithmetic_subarray[i - 1];
            }
        }

        if (last_break != length)
            total_count += arithmetic_subarray[length - 1];

        return total_count;
    }
};
// @leet end
