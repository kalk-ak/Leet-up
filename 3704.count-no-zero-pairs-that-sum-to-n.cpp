// @leet start
#include <type_traits>
#include <unordered_map>
class Solution
{
  public:
    long long countNoZeroPairs(long long n)
    {
        std::unordered_map<int, bool> seen_before;
        long long count = 0;
        for (long long i = 1; i < n; i++)
        {
            int other = n - i;

            if (is_no_zero(other, seen_before) and is_no_zero(i, seen_before))
            {
                count += 1;
            }
        }
        return count;
    }

  private:
    bool is_no_zero(int a, int n, std::unordered_map<int, bool> &seen_before)
    {
        if (seen_before.find(a) != seen_before.end())
        {
            return seen_before[a];
        }

        bool contains_zero = false;
        int num = a;
        while (num > 0)
        {
            int current = num % 10;

            if (current == 0)
            {
                contains_zero = true;

                // Automatically add all the
                int new_num = a * 10;
                while (new_num < n)
                {
                    seen_before[new_num] = false;
                    new_num *= 10;
                }
                break;
            }

            num = num / 10;
        }

        seen_before[a] = not contains_zero;
        return not contains_zero;
    }
};
// @leet end
