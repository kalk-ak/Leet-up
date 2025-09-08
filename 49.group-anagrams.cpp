// @leet start
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::vector;

class Solution
{
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // LOGIC: Sort each string and use them as a key to group the strings
        std::unordered_map<string, vector<string>> group;

        for (const string &s : strs)
        {
            string current = s;
            // Sort the string so that the key for the same string always stays the same
            std::sort(current.begin(), current.end());

            group[current].push_back(s);
        }

        vector<vector<string>> answer;
        // Group each vector for each key in the hashmap
        for (const auto &pair : group)
            answer.push_back(pair.second);

        return answer;
    }
};

// @leet end
