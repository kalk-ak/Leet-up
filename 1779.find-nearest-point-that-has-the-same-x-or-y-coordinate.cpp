// @leet start
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <ratio>
#include <vector>

using std::vector;

class Solution
{
  public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {

        // Data structure to store the closest distance and the index it occurs at
        int closest[] = {INT32_MAX, -1};

        // Loop through all possible combinations and keep track with the point with the smallest
        // distance
        size_t length = points.size();
        for (size_t i = 0; i < length; i++)
        {
            int xi = points[i][0], yi = points[i][1];
            if (xi == x || yi == y)
            {
                size_t current_norm = std::abs(x - points[i][0]) + std::abs(y - points[i][1]);

                if (current_norm < closest[0])
                {
                    closest[0] = current_norm;
                    closest[1] = i;
                }
            }
        }
        return closest[1];
    }
};
// @leet end
