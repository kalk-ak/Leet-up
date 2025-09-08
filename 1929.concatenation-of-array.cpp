// @leet start
#include <system_error>
#include <vector>
class Solution
{
  public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        // get the size of the arary so it can be cahched
        size_t n = nums.size();

        // Create an array of double the size to store the results
        std::vector<int> results(n);

        for (size_t i = 0; i < n; ++i)
            results[i] = results[i + n] = nums[i];

        return results;
    }
};
// @leet end
