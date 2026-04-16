// @leet start
#include <algorithm>
#include <exception>
#include <functional>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>
class Solution
{
  public:
    std::vector<int> sortByReflection(std::vector<int> &nums)
    {
        int length = nums.size();

        std::vector<int> reflected_vals(length); // vector to store the reflected numbers

        // Iterate through each number in the input vector and calculate its reflected value
        for (int i = 0; i < length; ++i)
        {
            // Store the current number
            int current = nums[i];

            // stores the reflected number
            int reflected_num = 0;

            // Reflect the current number
            while (current > 0)
            {
                int current_one_bit = current & 1; // Get the least significant bit

                // Make space by shifting
                reflected_num <<= 1;
                reflected_num |= current_one_bit;

                // // DEBUG:
                // std::cout << "Current one bit: " << current_one_bit << ", Current: " << current
                //           << ", Reflected number: " << reflected_num << "\n";

                // shift the current number to the right to process the next bit
                current >>= 1;
            }

            reflected_vals[i] = reflected_num;
        }

        // Create an index array that is going to be sorted based on the reflected array
        std::vector<int> indexs(length);
        int current_index = 0;
        for (size_t i = 0; i < length; i++)
        {
            indexs[i] = current_index++;
        }

        // Sort the indexes based on the reflected values using a custom comparator
        std::stable_sort(indexs.begin(), indexs.end(),
                         [&reflected_vals, &nums](int a, int b)
                         {
                             if (reflected_vals[a] != reflected_vals[b])
                                 return reflected_vals[a] < reflected_vals[b];
                             else
                                 return nums[a] < nums[b];
                         }); // sorts in ascending order

        // Reorder the numbers based on the sorted index
        std::vector<int> sorted_nums(length);
        for (size_t i = 0; i < length; i++)
        {
            int index = indexs[i];
            sorted_nums[i] = nums[index];
        }

        return sorted_nums;
    }
};
// @leet end
