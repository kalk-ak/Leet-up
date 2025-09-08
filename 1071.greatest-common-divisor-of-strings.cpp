// @leet start
#include <string
class Solution
{
  public:
    string gcdOfStrings(string str1, string str2)
    {
        // start with the smallest string and incrementally check if the substing divides both
        int lenStr1 = str1.size(), lenStr2 = str2.size();

        string divisor, dividend;
        if (lenStr1 > lenStr2)
        {
            dividend = str1;
            divisor = str2;
        }
        else
        {
            dividend = str1;
            divisor = str2;
        }
    }

    bool isDivisor(string dividend, string divisor)
    {
        int lenStr = str.size(), lenDivisor = divisor.size();

        if (lenStr % lenDivisor != 0)
        {
            return false;
        }

        for (size_t i = 0; i < lenStr; i++)
        {
            if (dividend[i] != divisor[i % lenDivisor])
            {
                return false;
            }
        }

        return true;
    }
};
// @leet end
