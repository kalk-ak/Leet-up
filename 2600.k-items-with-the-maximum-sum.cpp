// @leet start class Solution
#include <algorithm>
class Solution
{
  public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
    {

        // LOGIC: Maximize ones and minimize negative ones
        int length = numOnes;
        int sum = std::min(k, numOnes);

        if (length >= k)
            return sum;

        length += numZeros;
        if (length >= k)
            return sum;

        // Get the remaining items from negative ones
        int remaining = k - length;

        return sum - remaining;
    }
};
// @leet end
