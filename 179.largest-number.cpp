// @leet start
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using std::vector;
using std::string;

class Solution
{
  public:
    string largestNumber(vector<int> &nums)
    {
        // Since the number len of the number would be the same for all numbers
        // we are going to concatenate the number whose first digit is the largestNumber
        std::sort(nums.begin(), nums.end(),
                  [](int a, int b)
                  {
                      return std::to_string(a) + std::to_string(b) >
                             std::to_string(b) + std::to_string(a);
                  });

		if (nums[0] == 0) return "0";



        std::stringstream answer;
        for (auto num : nums)
        {
            answer << num;
        }

        return answer.str();
    }

    int firstdigit(int num)
    {
        while (num > 10)
        {
            num = num / 10;
        }
        return num;
    }

    static bool checker(int a, int b)
    {
        string strA = std::to_string(a);
        string strB = std::to_string(b);

        int lenA = strA.size();
        int lenB = strB.size();

        for (int i = (lenA > lenB) ? lenB
                                   : lenA; // Set I as the min between length of A and length of B
             i > 0; i--)
        {
            const char charA = strA[i], charB = strB[i];
            if (charA == charB)
            {
                continue;
            }

            return charA > charB;
        }
        return (lenA < lenB) ? false : true;
    }
};
// @leet end
