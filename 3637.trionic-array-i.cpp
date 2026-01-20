// @leet start
class Solution
{
  public:
    bool isTrionic(vector<int> &nums)
    {
        int alterate_count = 0;

        int length = nums.size();

        int i = 0;
        int i_prev = i;
        while (i < (length - 1) and nums[i] < nums[i + 1])
        {
            ++i;
        }
        alterate_count += 1;
        if (i == length - 1 or i == i_prev)
            return false;

        i_prev = i;
        while (i < length - 1 and nums[i] > nums[i + 1])
        {
            ++i;
        }

        if (i == length - 1 or i == i_prev)
            return false;
        i_prev = i;
        while (i < length - 1 and nums[i] < nums[i + 1])
        {
            ++i;
        }

        return i == length - 1;
    }
};
// @leet end
