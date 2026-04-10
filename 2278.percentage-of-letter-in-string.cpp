// @leet start
#include <iostream>
#include <string>
class Solution
{
  public:
    int percentageLetter(std::string s, char letter)
    {
        int count = 0;

        for (const char &c : s)
        {
            if (c == letter)
                count += 1;
        }

        return (static_cast<double>(count) / s.size()) * 100;
    }
};
// @leet end
