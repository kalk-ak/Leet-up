// @leet start
#include <cstddef>
#include <immintrin.h>
#include <vector>

using std::vector;
class Solution
{
  public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        //
        //
        // // vector of 1s for vectorized subtraction
        // std::vector<int> ones(8, -1);
        // __m256i negative_ones = _mm256_set1_epi32(-1);
        //
        // // Perform the queries on a copy of nums and see if it becomes a zero array at the end
        // for (const auto & q : queries) {
        //
        // 	// Perform a vectorized operation
        // 	size_t i = q[0];
        // 	size_t n = q[1];
        // 	for (; i + 8 < n; i += 8) {
        // 		// Load 8 integers into a 256 bit register
        // 		__m256i vec_a = _mm256_loadu_si256((__m256i*) &nums[i]);
        //
        // 		// subtract the result
        // 		__m256i result = _mm256_add_epi32(vec_a, negative_ones);
        //
        // 		// store the result back
        // 		_mm256_storeu_si256((__m256i*) &nums[i], result);
        // 	}
        // 	for (; i < n; ++i) {
        // 		--nums[i];
        // 	}
        // }
        //
        // for (const int & n : nums) {
        // 	if (n > 0)
        // 		return false;
        // }
        //
        // return true;
        //

        // Instead of going through all the queries I will mark the start and end queries
        // with 1 and -1 to denote how many queries overlap between any index i and j
        // +1 means a query starts here and a -1 denotes a query ends here
        // to get the total number of queries that overlap until index i then that would be the sum
        // of the running total until the ith index
        size_t length = nums.size();

        // vector to store the length of array of markers (+1 and -1) to denote the start and end of
        // queries
        std::vector<int> overlaps(length + 1, 0);

        for (const auto &q : queries)
        {
            overlaps[q[0]] += 1;
            overlaps[q[1] + 1] -= 1;
        }

        // now the number of queries that overlap at any index i is the running sum of
        // the overlaps until index i
        // we would return false if the running total sum is less than nums[i]
        long running_sum = 0;
        for (size_t i = 0; i < length; i++)
        {
            running_sum += overlaps[i];

            if (nums[i] > running_sum)
                return false;
        }

        return true;
    }
};
// @leet end
