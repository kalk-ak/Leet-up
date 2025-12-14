// @leet start
#include <csignal>
#include <map>
#include <stdexcept>
#include <string>
#include <unordered_map>

#include <string.h>
#include <utility>
#include <vector>
using std::string;
class TimeMap
{
  public:
    // I am thinking of a nested hashmap as the inner data structure
    TimeMap()
    {
        // Constructor
        // Initialize the nested hashmap
    }

    void set(string key, string value, int timestamp)
    {
        mp[key].insert({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        std::string result = "";
        if (mp.count(key) != 0)
        {

            // Store the current map for better caching
            const auto &current_map = mp[key];

            // Get the upperbound of the insertion position of current timestamp
            auto it = current_map.upper_bound(timestamp);

            // if the itterator is still at the begining of the map then it must be empty
            if (it != current_map.begin())
            {
                --it;
                result = it->second;
            }
        }
        return result;
    }

  private:
    std::unordered_map<string, std::map<int, string>> mp;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @leet end
