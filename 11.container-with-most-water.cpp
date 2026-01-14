// @leet start
#include <algorithm>
#include <cassert>
#include <cstdint>
class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0, n = height.size(); // Stores the maximum area
        // LOGIC: Have every possible pair of 2 pairs and get the maximum area
        // for (int i = 0; i < n; ++i) {
        // 	assert(height[i] > -1);
        // 	for (int j = i + 1; j < n; ++j) {
        //
        // 		int height_max = std::min(height[i], height[j]);
        // 		int width = j - i;
        //
        // 		max_area = std::max(height_max * width, max_area);
        // 	}
        // }
        // return max_area;

        // LOGIC: Have two pointers at the end and the begining
        // and only move the smaller hegiht
        int i = 0, j = n - 1;
        while (i < j)
        {
            int height_min = std::min(height[i], height[j]);
            int width = j - i;

            max_area = std::max(max_area, height_min * width);

            if (height_min == height[i])
                ++i;
            else
                --j;
        }
        return max_area;
    }
};
// @leet end
