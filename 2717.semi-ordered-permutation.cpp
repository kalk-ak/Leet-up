// @leet start
#include <cstddef>
class Solution
{
  public:
    int semiOrderedPermutation(vector<int> &nums)
    {
        // Count how many elements are before 1 and how many are after n;
        // if n is before 1 then subtract 1;

        //
        // bool one_found = false, n_found = false; 		// Used to flag when we have seen 1 or n
        // int one_counter = 0, n_counter = 0;			// Count numbers before 1 and numbers after
        // n bool overlap = false;							// Used to check if they 1 and n overlap
        //
        // size_t length = nums.size();
        // for (size_t i = 0; i < length; i++) {
        // 	const int curr = nums[i];
        //
        // 	if (curr == 1) {
        // 		one_found = true;
        //
        // 		if (n_found) {
        // 			--one_counter;
        // 		}
        // 	}
        //
        // 	if (! one_found)
        // 		++one_counter;
        //
        // 	if (curr == length) {
        // 		n_found = true;
        // 		continue;
        // 	}
        //
        // 	if (n_found)
        // 		++n_counter;
        // }
        //
        // return one_counter + n_counter;

        const size_t length = nums.size();

        int index_of_1 = -1;
        int index_of_n = -1;

        for (size_t i = 0; i < length; i++)
        {
            const int curr = nums[i];
            if (curr == 1)
                index_of_1 = i;
            if (curr == length)
                index_of_n = i;
        }

        int sum = index_of_1 + (length - 1 - index_of_n);

        if (index_of_1 > index_of_n)
            --sum;

        return sum;
    }
};
// @leet end
