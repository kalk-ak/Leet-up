// @leet start
#include <cstddef>
#include <vector>
class Solution
{
  public:
    int countPrimes(int n)
    {
        // Used to count the number of prime numbers
        std::vector<bool> isprime(n, true);
        for (int num = 2; num * num < n; num++)
        {
            if (isprime[num])
            {
                for (size_t p = num * num; p < n; p += num)
                    isprime[p] = false;
            }
        }

        int count = 0;
        for (int i = 2; i < n; ++i)
        {
            bool b = isprime[i];
            if (b)
                ++count;
        }
        return count;
    }
};
// @leet end
