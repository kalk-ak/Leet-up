// @leet start
#include <cctype>
#include <sstream>
#include <string>
using std::string;
class Solution
{
  public:
    bool isPalindrome(string s)
    {
        // LOGIC: First start by filtering the alpha numeric charters in the string
        // then check if it is a Palindrome
        std::stringstream ss;
        for (const char &c : s)
        {
            if (std::isalnum(c))
            {
                ss << (char) std::tolower(c);
            }
        }

        string filtered = ss.str();

        // Now check if the filtered string is a Palindrome
        int i = 0, j = filtered.size() - 1;
        while (i < j)
        {
            if (filtered[i++] != filtered[j--])
                return false;
        }
        return true;
    }
};
// @leet end
