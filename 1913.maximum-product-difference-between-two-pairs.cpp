// @leet start
#include <algorithm>
#include <csetjmp>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>
class Solution
{
  public:
    // int maxProductDifference(vector<int> &nums)
    // {
    //     size_t n = nums.size();
    //
    //     int max = INT32_MIN;
    //     for (size_t i = 0; i < n; i++)
    //     {
    //         for (size_t j = i + 1; j < n; j++)
    //         {
    //             for (size_t k = j + 1; k < n; k++)
    //             {
    //                 for (size_t l = k + 1; l < n; l++)
    //                 {
    //                     int first_product = std::abs((nums[i] * nums[j]) - (nums[k] * nums[l]));
    //                     int second_product = std::abs((nums[i] * nums[k]) - (nums[j] * nums[l]));
    //                     int third_product = std::abs((nums[i] * nums[l]) - (nums[j] * nums[k]));
    //
    //                     if (first_product > max)
    //                         max = first_product;
    //
    //                     if (second_product > max)
    //                         max = second_product;
    //
    //                     if (third_product > max)
    //                         max = third_product;
    //                 }
    //             }
    //         }
    //     }
    //
    //     return max;
    // }
    //
    int maxProductDifference(std::vector<int> &nums)
    {
        int length = nums.size();

        // Handling edge case of lists less than length 4
        if (length < 4)
        {
            throw std::invalid_argument("Array length must be at least of length 4. Length of " +
                                        std::to_string(length) + " passed as an argument");
        }

        // A greedy approach where the array is sorted by the absolute value
        size_t n = nums.size();

        // Created a copied sort in n(log(n)) expected time
        std::vector<int> nums_copy;
        for (const int &n : nums)
        {
            auto pos = std::lower_bound(nums_copy.begin(), nums_copy.end(), n);
            nums_copy.insert(pos, n);
        }

        // Used for debugging the output
        // for (const int &n : nums_copy)
        // {
        //     std::cout << n << " ";
        // }
        // std::cout << std::endl;

        // Greedily we know that the first term should be the same sign
        int first_product = nums_copy[length - 1] * nums_copy[length - 2];
        int second_product = nums_copy[0] * nums_copy[1];
        int left = (first_product > second_product) ? first_product : second_product;

        int right = 0;
        // Ideally the second term should be different sign and maximum magnitude
        if ((nums_copy[0] ^ nums_copy[length - 1]) < 0)
        {
            // the smallest and largest number have opposite sign
            right = nums_copy[0] * nums_copy[length - 1];
        }
        else
        {
            right = nums_copy[0] * nums_copy[1];
        }

        return left - right;
    }
};
// @leet end
