// @leet start
#include <cassert>
#include <iostream>
#include <stdexcept>
class Solution
{
  public:
    int fillCups(vector<int> &amount)
    {

        // Greedy method is that fill up the largest cup and alternate between the other
        // two smaller ones. Goal is to try and maximize the amount of two cup fills

        // get the length and check for invalid arguments
        int length = amount.size();
        if (length != 3)
            throw std::invalid_argument("Amount must be of size 3");

        // Get the maximum amount and also store the index
        int max_amount = amount[0], max_index = 0;

        // Get the max value
        for (int i = 1; i < 3; i++)
        {
            if (amount[i] > max_amount)
            {
                max_amount = amount[i];
                max_index = i;
            }
        }

        std::cout << "MAX AMOUNT: " << max_amount << "\n";
        // get the other two indexes
        int first_index = (max_index + 1) % 3;
        int second_index = (max_index + 2) % 3;

        int counter = 0; // RETURNED: the counter of cup fills

        // Once you get the max value decrease it by 1 and decrease the other two values by 1 as
        // well. Do this until the max value is 0
        while (amount[max_index] > 0)
        {
            if (amount[first_index] > amount[second_index])
            {
                // alternate if the second index needs to be filled
                amount[first_index] -= 1;
            }
            else
            {
                amount[second_index] -= 1;
            }
            amount[max_index] -= 1;
            counter += 1;
        }

        // // Now decrease the remaining two cups until they are empty
        // while (amount[first_index] > 0 and amount[second_index] > 0) {
        // 	amount[first_index] -= 1;
        // 	amount[second_index] -= 1;
        // 	counter += 1;
        // }
        // PERF: Can be made into a constant operation by just taking the max of the two
        int max_between_remaining = max(amount[first_index], amount[second_index]);
        if (max_between_remaining > 0)
            counter += max_between_remaining;

        return counter;
    }
};
// @leet end
