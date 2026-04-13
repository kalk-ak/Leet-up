// @leet start
#include <cassert>
#include <climits>
#include <vector>
class Solution
{
  public:
    std::vector<std::vector<int>> largestLocal(std::vector<std::vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();

        assert(row == col);
        std::vector<std::vector<int>> answer(row - 2, std::vector<int>(row - 2));
        for (int i = 1; i < row - 1; ++i)
        {
            for (int j = 1; j < col - 1; ++j)
            {
                answer[i - 1][j - 1] = get_max(grid, i, j);
            }
        }
        return answer;
    }

  private:
    int get_max(std::vector<std::vector<int>> &grid, int i, int j)
    {
        int row = grid.size();

        int max = INT_MIN;
        for (size_t x = i - 1; x < i + 2; x++)
        {
            for (int y = j - 1; y < j + 2; y++)
            {
                if (grid[i][j] > max)
                    max = grid[i][j];
            }
        }
        return max;
    }
};
// @leet end
