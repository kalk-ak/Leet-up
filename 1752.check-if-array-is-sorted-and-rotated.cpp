// @leet start
#include <iostream>
class Solution
{
  public:
    bool check(vector<int> &nums)
    {
        // LOGIC: If found a break in order start from that position and check if the array is
        // sorted
        int length = nums.size();
        bool ordered = true;
        int start_index = -1;
        for (int i = 1; i < length; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                ordered = false;
                start_index = i;
                break;
            }
        }

        if (not ordered)
        {
            int i = 0;
            int limit = length - 1;
            while (i < limit)
            {
                int index = (start_index + i) % length;
                int next_idx = (index + 1) % length;
                if (nums[index] > nums[next_idx])
                {
                    std::cout << index << ", " << next_idx << ", " << start_index;
                    return false;
                }

                ++i;
            }
        }
        return true;
    }
};
// @leet end
