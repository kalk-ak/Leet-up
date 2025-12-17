// @leet start
#include <cassert>
#include <unordered_map>
#include <vector>
class Solution
{
  public:
    bool isValidSudoku(std::vector<std::vector<char>> &board)
    {
        // Initialize with size 9 to avoid Segfault
        int row_checker[9][9] = {0};
        int col_checker[9][9] = {0};
        int batch_checker[3][3][9] = {0};

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                const char &current = board[i][j];

                if (current == '.')
                    continue;

                assert('0' <= current && current <= '9');

                int char_to_int = current - '1';

                ++row_checker[i][char_to_int];
                if (row_checker[i][char_to_int] > 1)
                    return false;

                ++col_checker[j][char_to_int];
                if (col_checker[j][char_to_int] > 1)
                    return false;

                int new_row = i / 3;
                int new_col = j / 3;
                ++batch_checker[new_row][new_col][char_to_int];
                if (batch_checker[new_row][new_col][char_to_int] > 1)
                    return false;
            }
        }
        return true;
    }
};
// @leet end
