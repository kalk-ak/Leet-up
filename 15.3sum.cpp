// @leet start
#include <algorithm>
#include <array>
#include <atomic>
#include <functional>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using std::vector;
class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // // LOGIC: Have two loops get the two numbers and get the third number from a hashmap
        // // it needs to be a hashmap because the index need to be also stored to check that
        // // the numbers aren't the same index
        // struct ArrayHash
        // {
        //     size_t operator()(const std::array<int, 3> &a) const
        //     {
        //         size_t h = 0;
        //         for (const int &x : a)
        //         {
        //             h ^= std::hash<int>{}(x) + +0x9e3779b9 + (h << 6) + (h >> 2);
        //         }
        //         return h;
        //     }
        // };
        //
        // std::unordered_set<std::array<int, 3>, ArrayHash> seen;
        // std::vector<std::vector<int>> answer;
        //
        // std::unordered_multimap<int, int> number_index;
        // int length = nums.size();
        // for (size_t i = 0; i < length; i++)
        // {
        //     int curr = nums[i];
        //     number_index.insert({curr, i});
        // }
        // for (int i = 0; i < length; i++)
        // {
        //     for (int j = i + 1; j < length; j++)
        //     {
        //         // 0 = num1 + num2 + complement
        //         // complement = 0 - num1 - num2
        //         int num1 = nums[i], num2 = nums[j];
        //         int complement = 0 - num1 - num2;
        //
        //         if (number_index.count(complement))
        //         {
        //             auto range = number_index.equal_range(complement);
        //             for (auto it = range.first; it != range.second; ++it)
        //             {
        //                 if (it->second != i and it->second != j)
        //                 {
        //                     std::array<int, 3> arr({num1, num2, complement});
        //                     std::sort(arr.begin(), arr.end());
        //                     if (seen.count(arr))
        //                         continue;
        //                     answer.push_back({num1, num2, complement});
        //                     seen.insert(arr);
        //                     break;
        //                 }
        //             }
        //         }
        //     }
        // }
        //
        // return answer;

        // struct ArrayHash
        // {
        //     size_t operator()(const std::array<int, 3> &a) const
        //     {
        //         size_t h = 0;
        //         for (const int &x : a)
        //         {
        //             h ^= std::hash<int>{}(x) + (h << 6) + (h >> 2);
        //         }
        //         return h;
        //     }
        // };
        //
        // // LOGIC: for every itteration use Greedy two pointers to get the 2 remaining element
        // std::unordered_set<std::string> seen;
        // std::vector<std::vector<int>> answer;
        //
        // // Sort the vector so that greedy two pointers can be performed
        // std::sort(nums.begin(), nums.end());
        //
        // int length = nums.size();
        // for (int i = 0; i < length; i++)
        // {
        //     int j = i + 1, k = length - 1;
        //     while (j < k)
        //     {
        //         // 0 = val:=(nums[j] + nums[k]) + nums[i]
        //         // val = 0 - nums[i]
        //         int val = 0 - nums[i];
        //
        //         int sum = nums[k] + nums[j];
        //         if (sum > val)
        //         {
        //             --k;
        //         }
        //         else if (sum < val)
        //             ++j;
        //         else
        //         {
        //             std::array<int, 3> arr = {nums[i], nums[j], nums[k]};
        //             std::sort(arr.begin(), arr.end());
        //             std::string hash = std::to_string(arr[0]) + "_" + std::to_string(arr[1]) +
        //             "_" +
        //                                std::to_string(arr[2]);
        //             if (not seen.count(hash))
        //             {
        //                 answer.push_back({nums[i], nums[j], nums[k]});
        //                 seen.insert(hash);
        //             }
        //             ++j;
        //         }
        //     }

        // LOGIC: for every itteration use Greedy two pointers to get the 2 remaining element
        std::vector<std::vector<int>> answer;

        // Sort the vector so that greedy two pointers can be performed
        std::sort(nums.begin(), nums.end());

        int length = nums.size();
        for (int i = 0; i < length; i++)
        {
            // Handle duplicates for i
            if (i > 0 and nums[i] == nums[i - 1])
                continue;

            int j = i + 1, k = length - 1;
            while (j < k)
            {
                // 0 = val:=(nums[j] + nums[k]) + nums[i]
                // val = 0 - nums[i]
                int val = 0 - nums[i];

                int sum = nums[k] + nums[j];
                if (sum > val)
                {
                    --k;
                }
                else if (sum < val)
                    ++j;
                else
                {
                    answer.push_back({nums[i], nums[j], nums[k]});

                    while (j < k and nums[j] == nums[j + 1])
                        ++j;

                    while (j < k and nums[k] == nums[k - 1])
                        --k;
                    ++j;
                    --k;
                }
            }
        }
        return answer;
    }
};
// @leet end
