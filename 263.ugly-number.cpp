// @leet start
class Solution
{
  public:
    bool isUgly(int n)
    {
        // LOGIC: Continue factoring n with 2, 3, and 5 until we can't anymore. If we reach 1, then
        // it's ugly
        while (n > 1)
        {
            if (n % 2 == 0)
            {
                n /= 2;
            }
            else if (n % 3 == 0)
            {
                n /= 3;
            }
            else if (n % 5 == 0)
            {
                n /= 5;
            }
            else
                return false;
        }
        return true;
    }
};
// @leet end
