// @leet start
#include <algorithm>
#include <cstddef>
#include <sstream>
#include <string>
class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        std::sort(strs.begin(), strs.end(), [](const std::string &a, const std::string &b)
                  { return a.length() < b.length(); });

        // LOGIC: Have a pointer traverse the first element and check if the character is in all the
        // strings Get the length of the first string
        std::string firstStr = strs[0];
        size_t n = firstStr.length(), index = 0;

        // Store the longestCommonPrefix
        std::stringstream lcp;

        while (index < n)
        {
            char current = firstStr[index];

            size_t n = strs.size();
            for (size_t i = 0; i < n; ++i)
                if (strs[i][index] != current)
                    return lcp.str();

            lcp << current;
            ++index;
        }

        return lcp.str();
    }
};
// @leet end
