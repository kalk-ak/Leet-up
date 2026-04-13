// @leet start
#include <algorithm>
#include <execution>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
class Solution
{
  public:
    int minimizedStringLength(string s)
    {
        // // LOGIC: Create a hashmap to store the frequency of the characters in the string.
        // std::unordered_set<char> frequency;
        //
        // for (char c : s)
        //     frequency.emplace(c);
        //
        // return frequency.size();
        int frequency[26] = {0};
        int count = 0;
        for (const char c : s)
        {
            int new_index = c - 'a';

            if (frequency[new_index] == 0)
            {
                count += 1;
                frequency[new_index] = 1;
            }
        }
        return count;
    }
};
// @leet end
