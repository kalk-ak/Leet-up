// @leet start
#include <cmath>
#include <vector>
class Solution
{
  public:
    int trap(std::vector<int> &height)
    {

        int total_rain_water = 0;
        // LOGIC: For each height (h) the algorithm is going to look for
        // the highest pair height. Then the amount of rain water trapped
        // between the two pairs would be calculated as:
        // total area - (sum of heights in between)
        //
        int i = 0, n = height.size();

        const int limit = n - 1;
        while (i < limit)
        {
            int j = i + 1;
            // Look for the next highest pair

            int max_height = height[j], max_height_index = j;
            while (++j < n and max_height < height[i])
            {
                // get the next longest height
                if (height[j] > max_height)
                {
                    max_height_index = j;
                    max_height = height[j];
                }
            }

            // Now we are greedily sure that max_height stores the next consecutive height to store
            // the water
            {
                // Calculate the total rain water between the two pairs of index
                int total_area = std::min(max_height, height[i]) * (max_height_index - i - 1);

                for (int k = i + 1; k < max_height_index; ++k)
                {
                    // Subtract the heights in between
                    total_area -= height[k];
                }

                total_rain_water += total_area;
            }
            i = max_height_index;
        }
        return total_rain_water;
    }
};
// @leet end
