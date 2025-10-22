// @leet start
#include <cassert>
#include <cstddef>
#include <limits>
#include <stdexcept>
#include <vector>

using std::vector;
class Solution
{
  public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        size_t length = coordinates.size();

        if (length == 0)
            throw std::invalid_argument("Empty coordinates passed as an argument");

        if (length < 3)
            return true;

        double slope = Solution::getSlope(coordinates[0], coordinates[1]);

        for (size_t i = 1; i < length - 1; i++)
        {
            double new_slope = Solution::getSlope(coordinates[i], coordinates[i + 1]);
            if (std::abs(slope - new_slope) > 1e-6)
                return false;
        }
        return true;
    };

    static double getSlope(vector<int> point1, vector<int> point2)
    {
        // Slope = (y2 - y1) / (x2 - x1)
        double x_diff = point2[0] - point1[0], y_diff = point2[1] - point1[1];

        if (x_diff == 0)
        {
            return std::numeric_limits<double>::infinity();
        }

        return y_diff / x_diff;
    }
};
// @leet end
