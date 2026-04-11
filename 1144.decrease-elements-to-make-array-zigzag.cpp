// @leet start
class Solution
{
  public:
    int movesToMakeZigzag(std::vector<int> &nums)
    {
        // We can divide the process into two steps:
        // we can try the odd way and then also try the even way and return the min
        int even = movesToMakeZigzag_even(nums);
        int odd = movesToMakeZigzag_odd(nums);
        return std::min(even, odd);
    }

  private:
    int movesToMakeZigzag_even(std::vector<int> &nums)
    {
        int length = nums.size();
        if (length < 2)
            return 0;

        int count = 0;

        for (int i = 0; i < length; i += 2)
        {
            // Calculate how much we MUST decrease nums[i] to be strictly less than left/right
            int left_req = (i > 0) ? nums[i] - nums[i - 1] + 1 : 0;
            int right_req = (i + 1 < length) ? nums[i] - nums[i + 1] + 1 : 0;

            // Pick the largest required decrease (capped at 0 so we don't increase)
            int max_req = std::max({0, left_req, right_req});
            count += max_req;
        }
        return count;
    }

    int movesToMakeZigzag_odd(std::vector<int> &nums)
    {
        int length = nums.size();
        if (length < 2)
            return 0;

        int count = 0;

        for (int i = 1; i < length; i += 2)
        {
            int left_req = (i > 0) ? nums[i] - nums[i - 1] + 1 : 0;
            int right_req = (i + 1 < length) ? nums[i] - nums[i + 1] + 1 : 0;

            int max_req = std::max({0, left_req, right_req});
            count += max_req;
        }
        return count;
    }
};
;
// @leet end
