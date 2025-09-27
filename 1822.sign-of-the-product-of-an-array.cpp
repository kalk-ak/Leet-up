// @leet start
class Solution
{
  public:
    int arraySign(vector<int> &nums)
    {

        int result = 1;

        // Loop over all the elements and multiply them
        for (auto num : nums)
        {
            if (num == 0)
                return 0;

            result *= (num < 0) ? -1 : 1;
        }
        return (result > 0) ? 1 : -1;
    }
};
// @leet end
