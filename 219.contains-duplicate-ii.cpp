// @leet start
#include <algorithm>
#include <cstdlib>
#include <unordered_map>
#include <vector>
class Solution
{
  public:
    bool containsNearbyDuplicate(vector<int> nums, int k)
    {
        // LOGIC: Sort the list and keep another array of the original positions

        int n = nums.size();
        std::vector<int> positions;
        // Populate our positions list to store the indexes
        for (int i = 0; i < n; ++i)
            positions.push_back(i);

        // Sort the positions depending on the original array
        std::sort(positions.begin(), positions.end(),
                  [&](const int a, const int b) { return nums[a] < nums[b]; });

        // Now sort the array
        std::sort(nums.begin(), nums.end());

        // Now just pass once and check if two elements are equal
        // and that their index difference is less than k
        int length = n - 1;
        for (size_t i = 0; i < length; i++)
        {
            if (nums[i] == nums[i + 1] && std::abs(positions[i] - positions[i + 1]) <= k)
            {
                return true;
            }
        }
        return false;
    }
};
// @leet end
