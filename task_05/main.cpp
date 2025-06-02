#include <string>
#include <vector>
#include <cassert>
#include <unordered_map>

static const std::unordered_map<char, int> MAP {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

class Solution {
    public:
        int romanToInt(std::string s) {
            int result = 0;
            int buffer = 0;
            for (auto y = s.rbegin(); y != s.rend(); ++y) {
                int i = MAP.at(*y);
                if (i < buffer) {
                    buffer -= i;
                }else {
                    result +=buffer;
                    buffer = i;
                }

            }
            result += buffer;
            return result ;
        }
    };
    int main () {
        Solution a;
        {assert(a.romanToInt("MCMXCIV") == 1994);}
        {assert(a.romanToInt("III") == 3);}
        {assert(a.romanToInt("LVIII") == 58);}
    }


