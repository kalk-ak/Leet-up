// @leet start
#include <cassert>
#include <string>
class Solution
{
  public:
    int minimumTimeToInitialState(const std::string word, const int k)
    {
        // LOGIC: I will try to do this itteratively where I would remove the first k characters
        // 		  and see if the new word matches with the first n letters of the word
        // NOTE: This logic can be made greeedy by just removing the first k letters until the words
        // match
        //
        assert(k > 0); // k should be greater than 0 to avoid infinite loop
        int counter = 0;
        int n = word.size(); // Length of the string for substring comparision
        std::string current = word;

        while (n > 0)
        {
            counter += 1;
            n -= k;
            if (k > current.size() || n < 0)
            {
                break;
            }
            // First remove the first k characters from the string
            current = std::string(current.begin() + k, current.end());

            if (current == word.substr(0, n))
                break;
        }

        return counter;
    }
};
// @leet end
