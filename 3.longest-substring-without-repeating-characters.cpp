// @leet start
#include <algorithm>
#include <string>
#include <unordered_set>
class Solution
{
  public:
    int lengthOfLongestSubstring(std::string s)
    {
        int length = s.size();
        int max_length = 0;

        // LOGIC: For each index have a sliding window of that checks a sub string without repeating
        // characters
        std::unordered_set<int> char_seen;

        int i = 0, j = 0;
        while (j < length)
        {
            char current_char = s[j];

            // If the current_char has been seen before then
            // move the first pointer until the sub-string
            // is only composed of unique characters
            if (char_seen.count(current_char))
            {
                do
                {
                    char_seen.erase(s[i]);
                } while (s[i++] !=
                         current_char); // Should remove the first instance of current_char
            }

            char_seen.insert(current_char); // Reinsert the current character
            max_length = std::max(max_length, (int) char_seen.size());
            ++j;
        }

        return max_length;
    }
};
// @leet end
