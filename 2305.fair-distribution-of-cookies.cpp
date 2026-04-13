// @leet start
#include <algorithm>
#include <climits>
#include <cstdint>
#include <vector>
class Solution
{
  public:
    int distributeCookies(vector<int> &cookies, int k)
    {
        // Using recursion I can enumerate all the possible distributions of cookies and calculate
        // the unfairness of each distribution. The unfairness of a distribution is the maximum
        // number of cookies that any child receives. I can keep track of the minimum unfairness
        // across all distributions and return it at the end.
        std::vector<int> child_sum(k, 0);
        return distribute_among_n_children(cookies, 0, cookies.size(), k, child_sum);
    }
    int distribute_among_n_children(const std::vector<int> &cookies, int index, const int length,
                                    int k, std::vector<int> &child_sum)
    {
        if (index >= length)
        {
            int max = INT_MIN;
            for (const int val : child_sum)
                max = std::max(val, max);
            return max;
        }

        int min_unfairness = INT_MAX;
        for (size_t i = 0; i < k; i++)
        {
            child_sum[i] += cookies[index];

            // Explore the next level of the recursion with the current distribution of cookies.
            int unfairness = distribute_among_n_children(cookies, index + 1, length, k, child_sum);
            min_unfairness = std::min(min_unfairness, unfairness);

            // backtrack and remove the current cookie from the current child before exploring the
            // next child.
            child_sum[i] -= cookies[index];
        }

        return min_unfairness;
    }
};
// @leet end
