// @leet start
#include <cmath>
#include <type_traits>
class Solution
{
  public:
    double myPow(double x, int n)
    {
        // LOGIC: Fast exponentiation
        // return std::pow(x, n);
        long exp = static_cast<long>(n);
        if (n < 0)
        {
            x = 1 / x;
            exp *= -1;
        }

        double result = 1;
        while (exp != 0)
        {
            if (exp & 1)
            {
                result *= x;
            }

            x *= x;
            exp >>= 1;
        }

        return result;
    }
};
// @leet end
