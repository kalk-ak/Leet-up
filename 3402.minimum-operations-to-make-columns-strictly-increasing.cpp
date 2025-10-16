// @leet start
#include <cstddef>
#include <stdexcept>
#include <vector>

using std::vector;

class Solution
{
  public:
    int minimumOperations(vector<vector<int>> &grid)
    {

        // Edge case where the grid is empyty
        if (grid.empty() || grid[0].empty())
            throw std::invalid_argument("Invalid grid passed as an argument. Grid must be a "
                                        "non-empty 2 dimensional vector");

        // The operations needed to make the all the columns strictly increasing
        int difference = 0;

        // Traverse each column and get the difference needed to make a column strictly increasing
        size_t row = grid.size(), column = grid[0].size();
        for (size_t j = 0; j < column; j++)
        {
            for (size_t i = 1; i < row; ++i)
            {
                if (grid[i][j] <= grid[i - 1][j])
                {
                    size_t needed = (grid[i - 1][j] - grid[i][j] + 1);
                    grid[i][j] += needed;
                    difference += needed;
                }
            }
        }
        return difference;
    }
};
// @leet end
