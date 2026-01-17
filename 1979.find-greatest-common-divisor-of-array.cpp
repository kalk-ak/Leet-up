// @leet start
#include <cassert>
#include <cstdint>
#include <stdexcept>
class Solution
{
  public:
    int findGCD(vector<int> &nums)
    {
        // LOGIC: Parse nums and get the smallest and largest number and then find the GCF of those
        // numbers
        int smallest = INT32_MAX, largest = INT32_MIN;

        for (const int i : nums)
        {
            if (i > largest)
                largest = i;

            if (i < smallest)
                smallest = i;
        }

        // // Now find the GCF of the smallest and the largest;
        // for (int i = smallest; i >= 0; --i) {
        // 	if (largest % i == 0 and smallest % i == 0)
        // 		return i;
        // }
        //
        return Solution::gcf_euclid(largest, smallest);

        throw std::logic_error(
            "Code error in calculating the GCF between two numbers. Should atleat return 1");
    }

    static int gcf_euclid(const int a, const int b)
    {
        int largest = (a > b) ? a : b;
        int smallest = (a < b) ? a : b;

        int remainder = largest % smallest;
        int last_divisor = smallest;
        while (remainder != 0)
        {
            largest = smallest;
            smallest = remainder;

            remainder = largest % smallest;
            last_divisor = smallest;
        }

        return last_divisor;
    }
};

// @leet end

