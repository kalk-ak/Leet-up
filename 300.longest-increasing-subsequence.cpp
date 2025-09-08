// @leet start
#include <cassert>
#include <cstddef>
class Solution
{
  public:
    int lengthOfLIS(vector<int> &nums)
    {

        // store length of the array so that it can be cached
        size_t n = nums.size();

        assert(n != 0);

        if (n == 1)
        {
            return 1;
        }

        size_t *dpArray = new size_t[n];

        // dynamic programming where past compute of longestSubsequence is used to compute
        // the new one
        for (size_t index = 0; index < n; ++index)
        {
            // initially the element by itself would have longestSubsequence of length 1
            dpArray[index] = 1;

            // Have pointer i to traverse the DP array to get the longestSubsequence
            size_t i = 0;

            while (i < index)
            {
                if ((nums[index] > nums[i]) && (dpArray[i] + 1) > (dpArray[index]))
                {
                    // Update the lo
                    dpArray[index] = dpArray[i] + 1;
                }
                ++i;
            }
        }
        // Get the maximum length in the dpArray
        int answer = dpArray[0];
        for (size_t i = 1; i < n; i++)
            if (dpArray[i] > answer)
                answer = dpArray[i];

        // Free the array
        delete[] dpArray;

        return answer;
    }
};
// @leet end
