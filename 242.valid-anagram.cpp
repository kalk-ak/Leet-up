// @leet start
#include <unordered_map>
#include <unordered_set>
class Solution
{
  public:
    bool isAnagram(string s, string t)
    {
        // LOGIC: store the characters in the two strings in two separate sets
        // 		Then check if the two sets are identical at the end
        std::unordered_map<char, int> firstCount, secondCount;

        size_t n = s.size();
        if (t.size() != n)
        {
            return false;
        }

        for (size_t i = 0; i < n; ++i)
        {
            char first = s[i], second = t[i];

            firstCount[first]++;
            secondCount[second]++;
        }

        for (auto pair : firstCount)
        {
            // if a character is in the first string and not in the second return an automatic false
            if (secondCount.find(pair.first) == secondCount.end())
                return false;

            // if the frequency of the character is not the same in the first and second string is
            // not the same return false
            if (pair.second != secondCount[pair.first])
                return false;
        }

        return true;
    }
};
// @leet end
