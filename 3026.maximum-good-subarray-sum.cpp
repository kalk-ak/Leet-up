// @leet start
#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>
class Solution
{
  public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        //     // LOGIC: A brute force approach would be to check every possible subarrry and get
        //     the sum
        //     // to make the summation faster, i will compute a sumation array
        //     int n = nums.size();
        //     std::vector<int> summs(n + 1);
        //
        //     // store the first element as 0
        //     nums[0] = 0;
        //
        //     // Store the increasing sum
        //     for (size_t i = 0; i < n; i++)
        //     {
        //         summs[i + 1] = nums[i] + summs[i];
        //     }
        //
        //     std::cout << summs << std::endl;
        //     int max_sum = INT32_MIN;
        //     for (int i = 0; i < n; ++i)
        //     {
        //         for (int j = 0; j < n; ++j)
        //         {
        //             // check if this subarrry fits the criteria of good subarrry
        //             if (std::abs(nums[i] - nums[j]) == k)
        //             {
        //                 int current_sum = summs[j + 1] - summs[i];
        //                 max_sum = std::max(max_sum, current_sum);
        //             }
        //         }
        //     }
        //
        //     return max_sum;
        // }

        // // logic: parse the array once and for each current number
        // // check if the target has been seen before through a hashmap
        // int n = nums.size();
        // std::vector<long long> sums(n + 1);
        //
        // // store the first element as 0 so that i can easily get the sum by subtracting
        // sums[0] = 0;
        // for (size_t i = 0; i < n; i++)
        // {
        //     sums[i + 1] = nums[i] + sums[i];
        // }
        //
        // // Hash map to store all the seen items
        // // where key is the element and value is the indice it is located at
        // std::unordered_multimap<int, int> seen;
        //
        // long long max_sum = LONG_LONG_MIN;
        // for (size_t j = 0; j < n; j++)
        // {
        //     long long current_val = nums[j];
        //
        //     // We need to check TWO targets because abs(nums[i] - nums[j]) == k
        //     // means nums[i] could be (nums[j] - k) OR (nums[j] + k)
        //     std::vector<long long> targets = {current_val - k, current_val + k};
        //
        //     for (long long target : targets)
        //     {
        //         // Ensure target is within int range before looking it up
        //         if (target < INT_MIN || target > INT_MAX)
        //             continue;
        //
        //         // Check if this target exists in our map
        //         if (seen.count((int) target))
        //         {
        //             auto range = seen.equal_range((int) target);
        //             // Iterate over EVERY index where this target appeared (Your Logic)
        //             for (auto it = range.first; it != range.second; ++it)
        //             {
        //                 int index = it->second;
        //                 long long current_sum = sums[j + 1] - sums[index];
        //                 max_sum = std::max(current_sum, max_sum);
        //             }
        //         }
        //     }
        //
        //     seen.emplace(nums[j], j);
        // }
        //
        // return (max_sum == LLONG_MIN) ? 0 : max_sum;

        // LOGIC: Parse the array once and for each current number
        // check if the target has been seen before through a hashmap
        int n = nums.size();
        std::vector<long long> sums(n + 1);

        // store the first element as 0 so that i can easily get the sum by subtracting
        sums[0] = 0;
        for (size_t i = 0; i < n; i++)
        {
            sums[i + 1] = nums[i] + sums[i];
        }

        // Hash map to stoer all the seen items
        // where key is the element and value is the indice it is located
        // We store in a greedy format in the map where we only keep the biggest
        // sum
        std::unordered_map<int, int> seen;
        long long max_sum = LLONG_MIN;
        for (int j = 0; j < n; ++j)
        {
            // check if target is in the hashmap
            // NOTE: that i have to do it twice
            // one for addition and the other for subtracting
            const auto targets = {nums[j] + k, nums[j] - k};

            for (auto &target : targets)
            {
                // Check for addition and subtracting
                if (seen.find(target) != seen.end())
                {
                    int index = seen[target];
                    long long current_sum = sums[j + 1] - sums[index];
                    max_sum = std::max(max_sum, current_sum);
                }
            }

            // Add the current index for future reference
            int current_key = nums[j];
            if ((seen.find(current_key) == seen.end()) || sums[j + 1] < sums[seen[current_key] + 1])
            {
                // check which sum is greater to store greedil			}
                seen[current_key] = j;
            }
        }
        return (max_sum == LLONG_MIN) ? 0 : max_sum;
    }
};
// @leet end
