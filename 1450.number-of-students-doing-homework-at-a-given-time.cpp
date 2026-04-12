j / @leet start class Solution
{
  public:
    int busyStudent(vector<int> &startTime, vector<int> &endTime, int queryTime)
    {
        // assuming the vectors are correctly formated
        int length = startTime.size();
        int count = 0;
        for (int i = 0; i < length; ++i)
        {
            if (queryTime >= startTime[i] && queryTime <= endTime[i])
            {
                ++count;
            }
        }
        return count;
    }
};
// @leet end
