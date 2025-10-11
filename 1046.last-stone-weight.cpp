// @leet start
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <stdexcept>
#include <vector>
class Solution
{
  public:
    int lastStoneWeight(std::vector<int> &stones)
    {

        // EDGE case where the stones are empty or of length 1
        size_t n = stones.size();
        if (n == 0)
        {
            throw std::invalid_argument("Empty array passed as an argument");
        }
        if (n == 1)
        {
            return stones[0];
        }

        // We are first going to start by sorting the stones in descending order
        // First create a copy of the array so that i don't modify the original parameter
        std::vector<int> copy_stones;
        for (int n : stones)
        {
            auto pos = std::lower_bound(copy_stones.begin(), copy_stones.end(), n);
            copy_stones.insert(pos, n);
        }

        // Now that we have a copy of the vector sorted we are going to continually smash the last
        // two elements and insert the absolute difference
        while (copy_stones.size() > 1)
        {
            const int largest = copy_stones.back();
            copy_stones.pop_back();
            const int second_largest = copy_stones.back();
            copy_stones.pop_back();

            // Get the absolute difference
            const int absolute_diff = std::abs(largest - second_largest);

            // Insert the absolute difference
            auto pos = std::lower_bound(copy_stones.begin(), copy_stones.end(), absolute_diff);
            copy_stones.insert(pos, absolute_diff);
        }
        return copy_stones[0];
    }
};
// @leet end
