// @leet start
#include <cstddef>
class Solution
{
  public:
    int countSeniors(vector<string> &details)
    {
        int counter = 0;

        // Iterate for all the customers in the array
        for (auto &customer : details)
        {
            int age = 0;

            char first = customer[11] - '0', second = customer[12] - '0';
            age += (first * 10) + second;

            if (age > 60)
            {
                ++counter;
            }
        }
        return counter;
    }
};
// @leet end
