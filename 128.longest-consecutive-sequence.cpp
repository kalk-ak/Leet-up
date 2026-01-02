// @leet start
#include <algorithm>
#include <set>
#include <unordered_set>
class Solution
{
  public:
    int longestConsecutive(vector<int> &nums)
    {
        // // LOGIC: First create a sorted map and then
        // // itterate in a sorted manner trying to find the longest sequence
        //
        // // Edge case fast return
        // int n = nums.size();
        // if (n < 2)
        //     return n;
        //
        // std::set<int> seen;
        //
        // // Parse nums and populate seen
        // for (const int &i : nums)
        //     seen.emplace(i);
        //
        // // Now parse the set and figure out the longest consequetive sequence
        // int i = 0, j = 0;
        // auto it = seen.begin();
        // int prev = *it;
        //
        // int max_counter = 1;
        // int counter = 1; // Counter to store the longest consequetive sequence
        // for (++it; it != seen.end(); ++it)
        // {
        //     const int &current = *it;
        //
        //     if (current == prev + 1)
        //     {
        //         counter += 1;
        //     }
        //     else
        //     {
        //
        //         max_counter = std::max(counter, max_counter);
        //         counter = 1; // Reset counter
        //     }
        //     prev = current;
        // }
        // max_counter = std::max(counter, max_counter);
        //
        // return max_counter;

        // LOGIC: First store the elements in an unordered set
        // then only start counting if the current number is the start of a consequetive sequence
        std::unordered_set<int> seen(nums.begin(), nums.end());

        int max_counter = 0;
        for (int number : seen)
        {
            if (seen.count(number - 1) == 0)
            {
                int counter = 1;

                int curr = number + 1;
                while (seen.count(curr))
                {
                    ++curr;
                    ++counter;
                }

                max_counter = std::max(counter, max_counter);
            }
        }
        return max_counter;
    }
};
// @leet end
