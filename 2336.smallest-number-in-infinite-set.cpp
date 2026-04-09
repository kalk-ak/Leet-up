// @leet start
#include <unordered_set>
class SmallestInfiniteSet
{
  public:
    SmallestInfiniteSet()
    {
        // Create a hash set to store all the numbers that have been removed from the object
        this->removed = std::unordered_set<int>();

        this->current_smallest = 1;
    }

    int popSmallest()
    {
        int return_value = current_smallest;
        removed.insert(current_smallest++);

        // check if the next Smallest number has been removed
        while (removed.count(current_smallest))
        {
            ++current_smallest;
        }

        return return_value;
    }

    void addBack(int num)
    {
        if (num < current_smallest)
        {
            current_smallest = num;
        }
        if (removed.find(num) != removed.end())
        {
            removed.erase(num);
        }
    }

  private:
    std::unordered_set<int> removed;
    unsigned long long current_smallest;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @leet end
