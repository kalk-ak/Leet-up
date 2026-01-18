// @leet start
#include <algorithm>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
class Solution
{
  public:
    std::string reverseWords(std::string s)
    {
        // LOGIC: First separate each word by white space
        // then reverse each word

        std::vector<std::string> tokens;

        int i = 0, length = s.size();
        while (i < length)
        {
            int j = i;
            while (not std::isspace(s[j]) and j < length)
            {
                ++j;
            }

            // Now the pointer between i and j is a word
            std::reverse(s.begin() + i, s.begin() + j);
            i = ++j;
        }

        return s;

        // Now reverse each word in the string;
    }
};
// @leet end
