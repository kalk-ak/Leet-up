// @leet start
#include <algorithm>
#include <endian.h>
#include <sys/select.h>
#include <vector>
class Solution
{
  public:
    int maxProfit(std::vector<int> &prices)
    {
        int max_profit = 0;
        // LOGIC: (Greedy) Keep track of the minumum price seen so far
        // and continue scanning for the next minumum element

        // EDGE Case checker
        int length = prices.size();
        if (length < 2)
            return 0;

        int minimum_price = prices[0];
        for (size_t i = 1; i < length; i++)
        {
            int profit = prices[i] - minimum_price;

            if (prices[i] < minimum_price)
                minimum_price = prices[i];

            max_profit = std::max(profit, max_profit);
        }
        return max_profit;
    }
};
// @leet end
