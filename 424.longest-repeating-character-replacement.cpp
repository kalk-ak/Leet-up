// @leet start
#include <algorithm>
#include <atomic>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <execution>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>
class Solution
{
  public:
    int characterReplacement(std::string s, int k)
    {
        // LOGIC: have a sliding window and keep track of the most frequent char in the window
        // increase the window size until the number of chars that are not the most frequent char is
        // more than k
        int i = 0, j = 0;
        int length = s.size();

        // Store the frequency of each letter in the current window
        int count[27] = {0};
        int max_freq = 0;
        int max_len = 0;

        while (j < length)
        {
            // increment the count in the window
            char curr_char = s[j];
            count[curr_char - 'A'] += 1;

            // Update the max frequency in the window
            max_freq = std::max(max_freq, count[curr_char - 'A']);

            // Get the count of the other characters in the window
            int count_other_chars = (j - i + 1) - max_freq;

            if (count_other_chars > k)
            {
                curr_char = s[i];
                count[curr_char - 'A'] -= 1;
                ++i;
            }

            // Update the max_len
            max_len = std::max(max_len, (j - i + 1));

            ++j;
        }
        return max_len;
    }
    // int characterReplacement(std::string s, int k)
    // {

    //       // LOGIC: have a sliding window and keep track of the most frequent char in the window
    //       // increase the window size until the number of chars that are not the most frequent
    //       char is
    //       // more than k
    //       //
    //       // TEST: when k = 0
    //
    //       // ===== EDGE CASE ======
    //       int length = s.size();
    //       if (k == 0 and length > 0)
    //           return longest_continous_char(s);
    //
    //       if (k > length)
    //           return length;
    //
    //       if (length < 3)
    //           return std::min(length, k);
    //
    //       // ==== END EDGE CASE ======
    //
    //       // Hashmap to store the frequency of chars in the window
    //       std::unordered_map<char, int> frequency;
    //
    //       // keeps track of the longest repeating char
    //       int len_longest_repeating_char = 0;
    //
    //       char most_frequent_char = s[0]; // variable to store the current most_frequent_char
    //
    //       int i = 0;               // Start of the window
    //       int j = 0;               // end of the window
    //       int num_other_chars = 0; // Capped at k
    //
    //       while (j < length )
    //       {
    //           if (num_other_chars <= k and j < length)
    //           {
    //               // we can extend the end of window
    //               char curr_char = s[j];
    //               frequency[curr_char] += 1;
    //
    //               if (curr_char != most_frequent_char)
    //                   num_other_chars += 1;
    //
    //               ++j;
    //           }
    //           else
    //           {
    //               len_longest_repeating_char = std::max(j - i, len_longest_repeating_char);
    //               char new_most_freq = get_most_freq(frequency);
    //
    //               if (frequency[new_most_freq] == frequency[most_frequent_char])
    //               {
    //
    //                   // Contract the window
    //                   while (num_other_chars > k and i < j)
    //                   {
    //                       char curr_char = s[i];
    //                       frequency[curr_char] -= 1;
    //
    //                       if (curr_char != most_frequent_char)
    //                           num_other_chars -= 1;
    //
    //                       ++i;
    //                   }
    //
    //                   // most_frequent_char = get_most_freq(frequency);
    //                   //
    //                   // assert(most_frequent_char != '\0');
    //               }
    //               // TEST: A, B, B, B
    //               else
    //               {
    //                   // Change of most_frequent_char
    //                   most_frequent_char = new_most_freq;
    //
    //                   // num_other_chars = length_of_window - most_frequent_char
    //                   num_other_chars = (j - i) - frequency[most_frequent_char];
    //
    //                   if (num_other_chars > k)
    //                   {
    //                       // print debugging logs
    //                       std::cout << "K = " << k << "\ns = " << s << "\ni = " << i << "\nj = "
    //                       << j
    //                                 << "\nnew_most_freq = " << new_most_freq
    //                                 << "\nfrequency_of_most_frequent_char = "
    //                                 << frequency[most_frequent_char]
    //                                 << "\nnum_other_chars = " << num_other_chars;
    //
    //                       throw std::logic_error("Not correctly switching most_frequent_char");
    //                   }
    //
    //               }
    //           }
    //       }
    //
    //       len_longest_repeating_char = std::max(len_longest_repeating_char, j - i);
    //
    //       if (num_other_chars > k)
    //       {
    //           len_longest_repeating_char -= 1;
    //           std::cout << "Subtracting one";
    //           std::cout << "most_frequent_char = " << most_frequent_char;
    //       }
    //
    //       return len_longest_repeating_char;
    //   }
    //
    // private:
    //   char get_most_freq(std::unordered_map<char, int> &frequency_map)
    //   {
    //       char most_frequent_char = '\0';
    //       int max_freq = 0;
    //
    //       for (auto &pair : frequency_map)
    //       {
    //           if (frequency_map[pair.first] > max_freq)
    //           {
    //               most_frequent_char = pair.first;
    //               max_freq = pair.second;
    //           }
    //       }
    //
    //       return most_frequent_char;
    //   }
    //
    //   int longest_continous_char(std::string &s)
    //   {
    //       int i = 0, j = 0;
    //
    //       int longest_continous_char = 0;
    //       int length = s.size();
    //
    //       while (j < length)
    //       {
    //           char curr_char = s[i];
    //
    //           while (s[j] == curr_char and j < length)
    //           {
    //               ++j;
    //           }
    //
    //           longest_continous_char = std::max(longest_continous_char, j - i);
    //
    //           i = j;
    //       }
    //
    //       return longest_continous_char;
    //   }
};
// @leet end
