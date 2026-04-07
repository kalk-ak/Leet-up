// @leet start
#include <iostream>
#include <vector>
class Solution
{
  public:
    long long minEnd(int n, int x)
    {
        // EDGE CASE:
        if (n < 2)
            return x;

        // LOGIC: for each element in the array first flip the zero bits
        // 		flip the bit next to the maximum position of the '1' bit in the binary
        //	 	representation of x, until we have n elements in the array. order

        // Get the position of zero bits and the maximum position of the '1' bit in the binary
        // representation of x
        bool zero_pos[64] = {0};
        int max_pos = 0;
        for (int i = 0; i < 64; i++)
        {
            if (((1LL << i) & x) > 0)
                max_pos = i;
            else
            {
                zero_pos[i] = 1;
            }
        }

        // flip all the zeros to 1, incrementally
        int index = 1;
        std::vector<long long> answer(n);
        answer[0] = x;

        for (int i = 0; i < 64; i++)
        {
            if (zero_pos[i] == 1)
            {
                // fip the zero bit at index i
                if (index < n)
                {
                    answer[index] = (1LL << i) | (answer[index - 1]);
                    index += 1;
                }
                else
                {
                    return answer[n - 1];
                }
            }
        }

        int i = 0;
        while (index < n)
        {
            answer[index] = answer[n - 1] | (1LL << (max_pos + i));
            ++i;
            index += 1;
        }

        return answer[n - 1];
    }
};
// @leet end
