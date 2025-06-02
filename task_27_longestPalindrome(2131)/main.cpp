#include <cassert>
// #include <map>
#include <string>
#include <unordered_map>
// #include <unordered_set>
#include <vector>
#include <cstdint>

using namespace std::literals;

class Solution {
   public:
    int longestPalindrome(std::vector<std::string>& words) {

        std::unordered_map<uint16_t, int> pair;
        std::unordered_map<uint16_t, int> one;
        int count = 0;
        for (auto& word : words) {
            uint16_t key = (word[0] << 8 | word[1]);
            if (word[0] == word[1]) {
                ++one[key];
                if (one[key] == 2) {
                    one.erase(key);
                    count += 4;
                }

                // auto it = one.find(word);
                // if (it->second == 2) {

                // }
            } else {
                uint16_t revers = (word[1] << 8 | word[0]);
                // ++pair[key];
                // auto it = pair.find(revers);
                if (pair[revers] > 0) {
                    --pair[revers];
                    count += 4;
                    // --pair[key];
                }else {
                    ++pair[key];
                }
            }
        }
        if (one.size() > 0) {
            count += 2;
        }

        return count;
    }
};

int main() {
    Solution s;
    {
        std::vector<std::string> v{"bb"s, "bb"s};
        assert(4 == s.longestPalindrome(v));
    }
    {
        std::vector<std::string> v{"bb"s, "bb"s, "bb"s};
        assert(6 == s.longestPalindrome(v));
    }
    {
        std::vector<std::string> v{"fq"s, "qf"s, "qo"s, "fo"s, "fo"s, "ff"s, "qq"s, "qf"s, "of"s, "of"s, "oo"s, "of"s, "of"s, "qf"s, "qf"s, "of"s};
        assert(14 == s.longestPalindrome(v));
    }
    {
        std::vector<std::string> v{"qo"s, "fo"s, "fq"s, "qf"s, "fo"s, "ff"s, "qq"s, "qf"s, "of"s, "of"s, "oo"s, "of"s, "of"s, "qf"s, "qf"s, "of"s};
        assert(14 == s.longestPalindrome(v));
    }
    {
        std::vector<std::string> v{"cl"s, "lc"s};
        assert(4 == s.longestPalindrome(v));
    }
    {
        std::vector<std::string> v{"ab"s, "ty"s, "yt"s, "lc"s, "cl"s, "ab"s};
        assert(8 == s.longestPalindrome(v));
    }
    {
        std::vector<std::string> v{"lc"s, "cl"s, "gg"s};
        assert(6 == s.longestPalindrome(v));
    }
    {
        std::vector<std::string> v{"cc"s, "ll"s, "xx"s};
        assert(2 == s.longestPalindrome(v));
    }
}
