// @leet start
#include <algorithm>
#include <cassert>
#include <climits>
#include <cstddef>
#include <vector>

using std::vector;
class Solution
{
  public:
    long long maxScore(vector<int> &a, vector<int> &b)
    {
        // // Most straight forward method would be to use a nested for loops
        // size_t a_length = a.size(), b_length = b.size();
        //
        // // Assert that a is size 4 and b has size greater or equal to 4
        // assert(a_length == 4 && b_length >= a_length);
        //
        // // Variable to store the max exression
        // long long maximum_score = LONG_LONG_MIN;
        // for (size_t i = 0; i < b_length; i++) {
        // 	for (size_t j = i + 1; j < b_length; j++) {
        // 		for (size_t k = j + 1; k < b_length; k++) {
        // 			for (size_t l= k + 1; l < b_length; l++) {
        // 				long long score = (a[0] * b[i]) + (a[1] * b[j]) + (a[2] * b[k]) + (a[3] *
        // b[l]); 				maximum_score = std::max(score, maximum_score);
        // 			}
        // 		}
        // 	}
        // }
        // return maximum_score;

        // Create a dynamic programing table to store the best possible score at each level of the
        // index
        size_t a_length = a.size(), b_length = b.size();

        // Optimal table for the maximum score until the ith element
        vector<long long> opt_table(4, LONG_LONG_MIN);

        for (size_t i = 0; i < b_length; i++)
        {

            if (opt_table[2] != LONG_LONG_MIN)
                opt_table[3] = std::max(opt_table[3], opt_table[2] + ((long long) b[i] * a[3]));

            if (opt_table[1] != LONG_LONG_MIN)
                opt_table[2] = std::max(opt_table[2], opt_table[1] + ((long long) b[i] * a[2]));

            if (opt_table[0] != LONG_LONG_MIN)
                opt_table[1] = std::max(opt_table[1], opt_table[0] + ((long long) b[i] * a[1]));

            opt_table[0] = std::max(opt_table[0], (long long) b[i] * a[0]);
        }

        return opt_table[3];
    }
};
// @leet end
