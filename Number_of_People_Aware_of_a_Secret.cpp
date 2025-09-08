// @leet start
#include <cassert>
#include <cstddef>
#include <iostream>
#include <unordered_map>
#include <vector>
using std::size_t;
class Solution {
public:
  // long MOD = 1000000007; Brute force method
  // int peopleAwareOfSecret(int n, int delay, int forget, int current_day = 1)
  // {
  // // recursive approach (bottom up)
  //   // Each recursive call represents a person that hasn't forgot about the
  //   // secret yet.
  //
  //   // Base case of of current_day reaching n
  //   if (current_day > n) {
  //     // current person still knows about the secret
  //     return 1;
  //   } else if (current_day > forget) {
  //     // current person forgot about the secret return 1 because by the end
  //     of
  //     // nth day this person wouldn't be remembering the secret
  //     return 0;
  //   }
  //   // base case of delay not being reached
  //   else if (current_day <= delay) {
  //     // Only increment the current_day and not yet tell any one
  //     return peopleAwareOfSecret(n, delay, forget, current_day + 1);
  //   } else {
  //     // We are going to increment another day and also tell another person
  //     // This can be simulated by two recursive calls
  //     return (peopleAwareOfSecret(n - current_day + 1, delay, forget,
  //                                 1) + // Telling to another person
  //             peopleAwareOfSecret(
  //                 n, delay, forget,
  //                 current_day + 1) // simulating another day for current
  //                 person
  //             ) %
  //            MOD;
  //   }
  // }

  // A memoization to store intermideate computed values
  // std::unordered_map<size_t, long long> memo;

  // Brute Force using for loop and memoization
  // int peopleAwareOfSecret(int n, int delay, int forget) {
  //
  //   long peopleAware = 1;
  //   // Use a for loop to simulate days passing
  //   for (size_t day = 1; day <= n; day++) {
  //     if (day > forget) {
  //       --peopleAware;
  //       break;
  //     } else if (day <= delay)
  //       // if delay isn't reached continue until it does
  //       continue;
  //
  //     else {
  //       // Share the secert with another person
  //       // first check if the value has been pre computed before
  //       if (memo.find(n - (day - 1)) != memo.end()) {
  //         // Value has been precomputed before
  //         peopleAware = (peopleAware + memo[n - (day - 1)]) % MOD;
  //       } else {
  //         // cache the computed values in memo
  //         long long value = peopleAwareOfSecret(n - (day - 1), delay,
  //         forget); memo[n - (day - 1)] = value; peopleAware = (peopleAware +
  //         value) % MOD;
  //       }
  //     }
  //   }
  //   return peopleAware;
  // }

  static void printMatrix(const std::vector<std::vector<int>> &matrix) {
    if (matrix.empty()) {
      std::cout << "Matrix is empty." << std::endl;
      return;
    }
    for (const auto &row : matrix) {
      for (int element : row) {
        std::cout << element << "\t";
      }
      std::cout << std::endl;
    }
  }
  // A dynamic programing approach
  // Checks if all the parameters have the expercted format
  int peopleAwareOfSecret(int n, int delay, int forget) {
    static constexpr long MOD = (long)(10e9 + 7);
    assert(delay > 0 && n >= delay && forget >= delay);

    // create a fixed matrix to store the number of people who know the secret
    const int row = n + 1, col = forget;
    std::vector<std::vector<int>> cache(row, std::vector<int>(col, -1));

    cache[0][0] = 1; // Only 1 person knows the secret on the first day

    // var i represents the current day
    // for each day the new people that finds out the secret equals all people
    // past the delay on the previos day
    for (int i = 1; i < row; ++i) {

      // Varaible to store the number of peopleAwareOfSecret that are going to
      // tell
      size_t secretAware = 0;

      // sum up the peopleAwareofSecret
      for (int j = delay; j < col - 1; ++j) {
        // get the total number of people that were aware and past the delay on
        // the previous day
        int current = cache[i - 1][j];

        if (current == -1)
          break;

        secretAware += current;
      }
      // set the new people Aware for the current_day
      cache[i][0] = secretAware;

      // propagate the people who havent yet forgot about the secret
      for (int j = 1; j < col; j++)
        cache[i][j] = cache[i - 1][j - 1];
    }

    // count how many people are aware on Day n
    size_t sum = 0;
    for (int i = 0; i < col; ++i) {
      int current = cache[n][i];
      if (current == -1)
        break;

      sum += current;
    }
    return sum;
  }
};

int main() {
  Solution sol;
  int answer = sol.peopleAwareOfSecret(4, 1, 3);
  int answer2 = sol.peopleAwareOfSecret(6, 2, 4);
}
// @leet end
