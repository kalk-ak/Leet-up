// @leet start
#include <csetjmp>
#include <string>
#include <vector>

using std::string;
using std::vector;
class Solution
{
  public:
    vector<int> executeInstructions(int n, vector<int> &startPos, string s)
    {
        // LOGIC: for each char I am going to simulate the movements and count how how many moves
        // until an invalid move happens

        // first define the moves that i can perform
        vector<int> UP = {-1, 0};
        vector<int> DOWN = {1, 0};
        vector<int> LEFT = {0, -1};
        vector<int> RIGHT = {0, 1};

        // Array to store the results
        int length = s.size();
        vector<int> result(length, 0);
        for (int i = 0; i < length; i++)
        {
            vector<int> current_pos = startPos;
            for (int j = i; j < length; j++)
            {
                // Execute the instructiosn and count until an invalid move happens
                char &c = s[j];
                switch (c)
                {
                case 'R':
                    // move to right and check if its valid
                    current_pos[0] += RIGHT[0];
                    current_pos[1] += RIGHT[1];
                    break;

                case 'L':
                    current_pos[0] += LEFT[0];
                    current_pos[1] += LEFT[1];

                    break;

                case 'U':
                    current_pos[0] += UP[0];
                    current_pos[1] += UP[1];
                    break;

                case 'D':
                    current_pos[0] += DOWN[0];
                    current_pos[1] += DOWN[1];
                    break;
                }

                if (current_pos[0] < 0 || current_pos[0] >= n || current_pos[1] < 0 ||
                    current_pos[1] >= n)
                {
                    // invalid move
                    break;
                }
                else
                {
                    // valid move
                    ++result[i];
                }
            }
        }

        return result;
    }
};
// @leet end
