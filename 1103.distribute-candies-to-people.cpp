// @leet start
#include <vector>
class Solution {
public:
  vector<int> distributeCandies(int candies, int num_people) {

    // vector to store the candies distribution
    std::vector<int> distribution(num_people, 0);

    size_t incremental = 1;

    // ittearte until there are no more candies
    while (candies > 0) {
      size_t index = (incremental - 1) % num_people;
      if (incremental > candies) {
        // last person to get the remaining candy
        distribution[index] += candies;
        candies = 0;
      } else {
        distribution[index] += incremental;
        candies -= incremental;
        ++incremental;
      }
    }
    return distribution;
  }
};
// @leet end
