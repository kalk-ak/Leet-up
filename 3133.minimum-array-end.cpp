// @leet start

#include <cassert>
#include <cstddef>

class Solution
{

  public:
    long long minEnd(int n, int x)
    {
        // edge case where x is negative or n <= 0
        assert(n >= 1 && x >= 0);

        // The array that we are going to return
        unsigned long long last = x;
        size_t i = 1, num = x + 1;

        while (i < n)
        {

            if ((x & num) == x)
            {
                last = num;
                i++;
            }
            ++num;
        }
        return last;
    }
};

// @leet end
