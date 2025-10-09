// @leet start
#include <cstddef>
#include <locale>
#include <unordered_map>
class Solution
{
  public:
    int maxOperations(vector<int> &nums, int k)
    {
        // First we would start by storing all the numbers in a hash map
        std::unordered_map<int, size_t> values; // In the hash map the key is the number and the
                                                // value is the frequency it occurs
        for (int num : nums)
            values[num] += 1;

        int operation_count = 0;

        // Now we are going to traverse thee list and check if its complement is in the hash map
        // if it is then decreasing the count by one would be equivalent to removing the number once
        for (int n : nums)
        {
            // complement + num = k
            int complement = k - n;
            if ((complement == n) && (values[n] < 2))
            {
                continue;
            }

            if (values.find(complement) != values.end())
            {
                if (values[complement] != 0 && values[n] != 0)
                {
                    values[n] -= 1;
                    values[complement] -= 1;
                    operation_count += 1;
                }
            }
        }
        return operation_count;
    }
};

// @leet end
