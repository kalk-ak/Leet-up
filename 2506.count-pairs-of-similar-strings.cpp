// @leet start
#include <csetjmp>
#include <map>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
class Solution
{
  public:
    int similarPairs(std::vector<std::string> &words)
    {
        // LOGIC: Convert each string into a set and check if the two sets are equal
        int length = words.size();
        std::map<std::set<char>, int> set_count;
        for (size_t i = 0; i < length; i++)
        {
            std::string current_word = words[i];
            std::set<char> current_set;
            for (const char &c : current_word)
                current_set.emplace(c);

            set_count[current_set] += 1;
        }

        int pair_counter = 0;
        for (auto &pair : set_count)
        {
            int n = pair.second;
            pair_counter += (n * (n - 1)) / 2;
        }

        return pair_counter;
    }
};
// @leet end
