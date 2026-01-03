// @leet start
#include <cassert>
#include <stdexcept>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using std::vector;
class Solution
{
  public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        // LOGIC: Store the numbers in a hash set and again
        // store the value and index as a hash set
        int index1 = -1, index2 = -1;
        int length = numbers.size();

        std::unordered_set<int> num_set(numbers.begin(), numbers.end());
        std::unordered_map<int, int> num_index_map;

        for (int i = 0; i < length; i++)
        {
            int key = numbers[i];

            // EDGE CASE where target is 0 and 0 + 0 = 0
            if (key == target / 2)
            {
                if (index1 == -1)
                    index1 = i;
                else
                {
                    index2 = i;
                    return {index1 + 1, index2 + 1};
                }
            }
            num_index_map[key] = i;
        }

        for (const int &n : numbers)
        {
            int complement = target - n;
            if (num_set.count(complement))
            {
                // sum found
                index1 = num_index_map[n] + 1;
                index2 = num_index_map[complement] + 1;

                return (index1 < index2) ? std::vector<int>{index1, index2}
                                         : std::vector<int>{index2, index1};
            }
        }
        throw std::invalid_argument("Parameter doesn't have two numbers that sum to target value");
    }
};
// @leet end
