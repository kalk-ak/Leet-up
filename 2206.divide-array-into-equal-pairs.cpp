// @leet start
#include <cstddef>
#include <unordered_map>
#include <unordered_set>
#include <vector>
class Solution {
public:
    bool divideArray(vector<int>& nums) {
        
		int n = nums.size();				// Size of the array
		
		// LOGIC: Use a hash map to store the frequency of each number
		// 		  If the frequency at the end isn't divisable by 2 then return false else return true
		std::unordered_map<int, int> frequency;

		// loop over the vector and use each element to index into the array and increment it;
		for (size_t i = 0; i < n; i++) {
			// if number isn't found then add it; if it is then increment the count
			int current = nums[i];

			if (frequency.find(current) != frequency.end())
				++frequency[current];

			else
				frequency[current] = 1;
		}
		
		// Go over the array one more time and if i find anything other than 0 or 2 then return false
		for (const auto pair : frequency)
			if (pair.second % 2 != 0) 
				return false;

		return true;
		
    }


// @leet end
