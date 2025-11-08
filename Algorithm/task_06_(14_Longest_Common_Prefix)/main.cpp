#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std::string_literals;
class Solution {
   public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::sort(strs.begin(), strs.end());
        for (size_t i = 0; i < strs[0].size(); ++i) {
            for (size_t j = 1; j < strs.size(); ++j) {
                if (strs[0][i] != strs[j][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};

int main() {
    Solution a;
    {
        std::vector<std::string> strs = {{"flower"s}, {"flow"s}, {"flight"s}};
        assert("fl"s == a.longestCommonPrefix(strs));
    }
    {
        std::vector<std::string> strs = {{"dog"s}, {"racecar"s}, {"car"s}};
        assert(""s == a.longestCommonPrefix(strs));
    }
    {
        std::vector<std::string> strs = {{"a"s}};
        assert("a"s == a.longestCommonPrefix(strs));
    }
}