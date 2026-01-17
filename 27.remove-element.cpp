// @leet start
#include <iostream>
#include <vector>

class Solution
{
  public:
    int removeElement(std::vector<int> &nums, int val)
    {
        // LOGIC: Removing from an array is o(n) so instead I would swap with the last element and
        // then pop later

        int i = 0, n = nums.size();
        while (i < n)
        {
            if (nums[i] == val)
            {
                // swap with the last element
                nums[i] = nums[n - 1];

                // decrease n
                --n;
            }
            else
                ++i;
        }

        // pop from the back
        nums.resize(i);
        return i;
    }
};
// @leet end
