// @leet start
class Solution
{
  public:
    int maximumCount(vector<int> &nums)
    {
        // LOGIC: Get the size of the array. Count the Negeative numbers, pass the zero and get the
        // positive with simple subtraction

        // index and length
        int i = 0, n = nums.size();

        int negagtive_count = 0;
        while (i < n)
        {
            int curr = nums[i];

            if (curr < 0)
                negagtive_count += 1;

            else if (curr > 0)
                break;

            ++i;
        }

        int positive_count = n - i;

        return (negagtive_count > positive_count) ? negagtive_count : positive_count;
    }
};
// @leet end
