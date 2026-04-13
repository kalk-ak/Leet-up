// @leet start
#include <iostream>
#include <stdexcept>
#include <vector>
class Solution
{
  public:
    int getMaximumGenerated(int n)
    {
        std::vector<int> nums(n + 1, -1);

        if (n < 0)
        {
            throw std::invalid_argument("n must be non-negative");
        }
        else if (n < 2)
        {
            return n;
        }

        nums[0] = 0;
        nums[1] = 1;

        int length = nums.size();
        int i = 0;
        int max = 1;
        while (2 * i <= n)
        {
            nums[2 * i] = nums[i];
            if (nums[2 * i] > max)
                max = nums[2 * i];

            if ((2 * i + 1) <= n)
            {
                nums[2 * i + 1] = nums[i] + nums[i + 1];
                if (nums[2 * i + 1] > max)
                {
                    max = nums[2 * i + 1];
                }
            }

            ++i;
        }

        return max;
    }
};
// @leet end
