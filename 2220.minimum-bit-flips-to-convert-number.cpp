// @leet start
#include <cstddef>
class Solution
{
  public:
    int minBitFlips(int start, int goal)
    {

        int diff = start ^ goal;

        int count = 0;
        for (size_t i = 0; i < 32; i++)
        {
            if (diff & (1 << i))
            {
                ++count;
            }
        }

        return count;
    }
};
// @leet end
