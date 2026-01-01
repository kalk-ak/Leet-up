// @leet start
#include <cassert>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

using long_url = std::string;
using short_url = std::string;

class Solution
{
  public:
    // Encodes a URL to a shortened URL.
    short_url encode(long_url longUrl)
    {
        // I can have an ID static variable that is a vector of chars
        // and every time I encode a new longUrl it increments the last element in the vector4
        if (encoded.find(longUrl) == encoded.end())
        {
            // longUrl is not seen before
            // encode it to the next avaiable code
            int index = next_available.size() - 1;

            // get the next_available encoding
            short_url current_available = to_short_url(next_available);

            // store the encoding
            encoded[longUrl] = current_available;
            decoded[current_available] = longUrl;

            // increment the "next_available" to the next state
            increment(index, next_available);
        }

        return encoded[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    long_url decode(short_url shortUrl)
    {
        if (decoded.find(shortUrl) == decoded.end())
            throw std::invalid_argument("Short URL has not been encoded before");

        return decoded[shortUrl];
    }

  private:
    // map from long_url to short_url (needed to check if the long_url is seen before)
    std::unordered_map<long_url, short_url> encoded;

    // map from short_url to long_url
    std::unordered_map<short_url, long_url> decoded;

    // Stores the next available encoding
    std::vector<int> next_available{0};

    // Stores the ALPHABET in the encoding
    const std::string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";
    const int NUM_BYTES = ALPHABET.size(); // stores the maximum of bytes in this encoding

    // Returns the encoding state as a short_url
    short_url to_short_url(std::vector<int> &encoding)
    {
        std::stringstream ss;

        for (const int &enc : encoding)
        {
            ss << ALPHABET[enc];
        }

        return ss.str();
    }

    // increments the last_encoded and returns the
    void increment(const int index, std::vector<int> &state)
    {
        assert(index < state.size());

        if (state[index] < NUM_BYTES - 1)
        {
            // increment the last_encoded and return
            state[index] += 1;
        }
        else if (index == 0)
        {
            // if the index is zero then it is a special case
            // All the encoding need to be zeroed and a new position should be appended
            for (int &enc : state)
                enc = 0;

            state.push_back(0);
        }
        else
        {
            // zero the current position and add 1 to the previous position
            state[index] = 0;
            increment(index - 1, state);
        }
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
// @leet end
