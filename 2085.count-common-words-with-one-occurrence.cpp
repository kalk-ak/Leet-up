// @leet start
#include <cstddef>
#include <string.h>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::vector;

class Solution
{
  public:
    int countWords(vector<string> &words1, vector<string> &words2)
    {
        std::unordered_map<string, size_t> count1;
        for (string s : words1)
        {
            count1[s] += 1;
        }

        std::unordered_map<string, size_t> count2;
        for (string s : words2)
        {
            count2[s] += 1;
        }

        int count = 0;
        for (string s : words1)
        {
            if (count2.find(s) != count2.end())
                if (count1[s] == 1 && count2[s] == 1)
                    count += 1;
        }
        return count;
    }
};
// @leet end
