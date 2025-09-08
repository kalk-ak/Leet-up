#include <cstddef>
#include <string>

using std::string;

class Solution
{
  public:
    string gcdOfStrings(string str1, string str2)
    {
        // start with the smallest string and incrementally check if the substing divides both
        int lenStr1 = str1.size(), lenStr2 = str2.size();

        string divisor = (lenStr1 > lenStr1) ? str1 : str2;

		size_t length = divisor.length();
		for (size_t i = 0; i < length; i++) {
			if (this->isDivisor(str1, divisor) && this->isDivisor(str2,divisor))
				return divisor;

			divisor.pop_back();
		}

		return "";
		
    }

    bool isDivisor(string dividend, string divisor)
    {
        int lenStr = dividend.size(), lenDivisor = divisor.size();

        if (lenStr % lenDivisor != 0)
            return false;

        for (size_t i = 0; i < lenStr; i++)
            if (dividend[i] != divisor[i % lenDivisor])
                return false;

        return true;
    }
};
