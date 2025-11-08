#include <algorithm>
#include <cassert>
// #include <deque>
#include <string>
// #include <unordered_set>
#include <unordered_map>

using namespace std::literals;

class Solution {
   public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> buf;
        int start = 0;
        int maxlenght = 0;
        for (int i = 0; i < s.size(); ++i) {
            char currant = s[i];
            if (buf.find(currant) != buf.end() && buf[currant] >= start) {
                start = buf[currant] + 1;
            }
            buf[currant] = i;
            maxlenght = std::max(maxlenght, i - start + 1);
        }
        return maxlenght;
    }
};

int main() {
    Solution s;
    assert(4 == s.lengthOfLongestSubstring("abckqczvsol"s));
    assert(4 == s.lengthOfLongestSubstring("abcabcd"s));
    assert(3 == s.lengthOfLongestSubstring("aabaab!bb"s));
    assert(5 == s.lengthOfLongestSubstring("tmmzuxt"s));
    assert(3 == s.lengthOfLongestSubstring("abcabcbb"s));
    assert(1 == s.lengthOfLongestSubstring("bbbbb"s));
    assert(3 == s.lengthOfLongestSubstring("pwwkew"s));
    assert(3 == s.lengthOfLongestSubstring("dvdf"s));
}