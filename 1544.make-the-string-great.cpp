// @leet start
#include <chrono>
#include <sstream>
#include <stdexcept>
class Solution
{
  public:
    string makeGood(string s)
    {
        int length = s.size();
        // Edge case detection
        if (length == 0)
        {
            return s;
        }
        // First store the difference between an uppercase and a lowercase letter
        int diff = std::abs('a' - 'A');

        // Build the final string in each loop
        char answer[length + 1];

        // First character is always added
        answer[0] = s[0];

        int i = 1, index = 1; // i is for "s" and index is for "answer"
        while (i < length)
        {
            if (std::abs(s[i] - s[i + 1]) == diff)
            {
                ++i; // Skip the next character as well
            }
            else if (index > 0 && std::abs(answer[index - 1] - s[i]) == diff)
            {

                index -= 1;
            }
            else
            {
                answer[index] = s[i];
                index += 1;
            }
            ++i;
        }
        answer[index] = '\0';

        return answer;
    }
};
// @leet end
