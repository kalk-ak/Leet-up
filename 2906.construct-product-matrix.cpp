#include <cstddef>
#include <vector>
// @leet start
//
using std::vector;
class Solution
{
  public:
    vector<vector<int>> constructProductMatrix(const vector<vector<int>> &grid)
    {
        // Passy by value so that i automatically copy the grid, modify and return it
        // I am thinking of a greedy method where i calculate the product of all
        // the rows and columns first then i just go backward once by dividing by p[i][j]
        size_t row = grid.size();
        size_t col = grid[0].size();
        vector<vector<int>> answer(row, vector<int>(col));
        long long product = 1;
        int MODULEUS = 12345;
        // NOTE: You can use loop unrolling if you want to make this more performat
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                answer[i][j] = product;
                product = (product * grid[i][j]) % MODULEUS;
            }
        }

        // Now calculate the suffix and this time I am going to go loop backwards
        product = 1;
        for (int i = row - 1; i > -1; --i)
        {
            for (int j = col - 1; j > -1; --j)
            {
                answer[i][j] = (answer[i][j] * product) % MODULEUS;
                product = (product * grid[i][j]) % MODULEUS;
            }
        }

        return answer;
    }
};
// @leet end
