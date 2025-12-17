// @leet start
#include <functional>
#include <vector>
class Solution
{
  public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // LOGIC: First store the product of all the elements as a long long
        // and then use simple division to get the result for each index.
        // WARNING: This approach may lead to overflow for large inputs.

        // calculate the product of all the elements
        long long product = 1;
        int zero_count = 0, last_zero_index = -1;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            const int &current = nums[i];
            if (current == 0)
            {
                ++zero_count;
                last_zero_index = i;
            }
            else
                product *= current;
        }

        // vector to store the product array except self
        std::vector<int> result(n, 0);

        switch (zero_count)
        {
        case 0:
            for (size_t i = 0; i < n; i++)
            {
                result[i] = product / nums[i];
            }
            break;
        case 1:
            result[last_zero_index] = product;
            break;

        default:
            break;
        }

        return result;
    }
};
// @leet end
