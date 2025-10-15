// @leet start
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution
{
  public:
    vector<int> diStringMatch(string s)
    {
        int i = 0;
        int n = s.size();

        vector<int> perm;
        for (auto c : s)
        {
            if (c == 'I')
            {
                perm.push_back(i++);
            }
            else
            {
                perm.push_back(n--);
            }
        }
        perm.push_back(n);
        return perm;
    }
};
// @leet end
