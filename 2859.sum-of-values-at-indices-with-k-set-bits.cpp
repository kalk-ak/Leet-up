// @leet start
#include <bit>
#include <bitset>
#include <exception>
#include <iostream>
class Solution
{
  public:
    int sumIndicesWithKSetBits(vector<int> &nums, int k)
    {
        int length = nums.size();
        int vector_sum = 0;
        for (int i = 0; i < length; ++i)
        {
            int current = nums[i];
            std::bitset<32> bits(i);
            if (bits.count() == k)
            {
                std::cout << "Summing " << i << std::endl;
                vector_sum += current;
            }
        }
        return vector_sum;
    }

  private:
    bool is_valid_binary(int n, int k)
    {
        // counter to keep track of the number of bits set to 1
        int count = 0;
        for (int i = 0; i < 32; i++)
        {
            if (n & (1 << i))
            {
                count += 1;
                if (count > k)
                {
                    // return early if the count exceeds k
                    return false;
                }
            }
        }

        return (count == k);
    }
};
// @leet end
