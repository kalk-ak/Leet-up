// @leet start
class Solution
{
  public:
    int getSum(int a, int b)
    {
        while (a != 0)
        {
            int carry = (a & b) << 1;
            b = a ^ b;
            a = carry;
        }
        return b;
    }
};
// @leet end
