// @leet start
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <vector>
class Solution
{
  public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        //      // Do a nested loop where for each anchor i expand a pointer until the cumulitive
        //      sum is >=
        //      // target
        //      size_t length = nums.size();
        //      int min_len = INT32_MAX;
        //
        //      for (size_t i = 0; i < length; i++)
        //      {
        //          int cumm_sum = nums[i];
        //
        // // Check if the number already achives target
        // if (cumm_sum >= target) {
        // 	min_len = 1;
        // 	break;
        // }
        //
        // // Now check in the sliding window of subararys
        //          for (size_t j = i + 1; j < length; j++)
        //          {
        // 	cumm_sum += nums[j];
        //
        // 	if (cumm_sum >= target) {
        // 		min_len = std::min(int(j - i + 1), min_len);
        // 		break;
        // 	}
        //          }
        //      }
        //
        //      return (min_len == INT32_MAX) ? 0 : min_len;

        // LOGIC: I am going to first store the running cummulative sum and
        // then the sum between two subararys can be found by subtraction
        // int length = nums.size();
        // std::vector<int> cumm_sum(length + 1);
        //
        // // First append the first element
        // cumm_sum[0] = 0;
        //
        // int i = 0;
        // while (i < length)
        // {
        //     cumm_sum[i + 1] = cumm_sum[i] + nums[i];
        //     ++i;
        // }
        //
        // int min_len = INT32_MAX;
        // // Now I can just get the sum between any two sub array by subtraction
        // for (int i = 0; i < length; ++i)
        // {
        //     for (int j = i + 1; j < length + 1; j++)
        //     {
        //         int sum = cumm_sum[j] - cumm_sum[i];
        //
        //         if (sum >= target)
        //         {
        //             min_len = std::min(j - i, min_len);
        //             break;
        //         }
        //     }
        // }
        // return (min_len == INT32_MAX) ? 0 : min_len;

        // LOGIC: Sliding window where i accumulate the sums then remove elements until I can't
        int length = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        int min_len = INT32_MAX;
        while (i < length)
        {
            sum += nums[i];

            ++i;

            // if the sum passes the target then try retracting the window from the left
            if (sum >= target)
            {
                while (sum >= target)
                {
                    sum -= nums[j];
                    ++j;
                }
                min_len = std::min(min_len, i - j + 1);
            }
        }

        return (min_len == INT32_MAX) ? 0 : min_len;
    }
};
// @leet end
