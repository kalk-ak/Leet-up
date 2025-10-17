// @leet start
class Solution
{
  public:
    bool canAliceWin(int n)
    {
        assert(n > 0);

        // Edge case where alice takes all the blocks in the first pick
        if (n < 10)
            return false;

        int to_take = 10;
        // alice takes 10 stones
        n -= to_take;
        to_take -= 1;
        bool alice_turn = true;

        while (to_take > 0)
        {
            n -= to_take;

            if (n < 0)
                break;
            to_take -= 1;
            alice_turn = !alice_turn;
        }

        return alice_turn;
    }
};
// @leet end
