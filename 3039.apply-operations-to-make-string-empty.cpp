// @leet start
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <sstream>
#include <string.h>
#include <unordered_map>

using std::string;

class Solution
{
  public:
    string lastNonEmptyString(string s)
    {

        std::unordered_map<int, int> count;

        for (const char &c : s)
        {
            count[c] += 1;
        }

        size_t maxCount = 0;
        for (const auto &pair : count)
        {
            if (pair.second > maxCount)
                maxCount = pair.second;
        }

        std::stringstream ss;
        int length = s.size();
        for (int i = length - 1; i >= 0; --i)
        {
            const char &c = s[i];
            if (count[c] == maxCount)
            {
                count[c] -= 1;
                ss << c;
            }
        }

        string answer = ss.str();
        std::reverse(answer.begin(), answer.end());
        return answer;
    }
};
// @leet end
