#include <algorithm>
#include <cassert>
// #include <deque>
#include <string>
// #include <unordered_set>
#include <unordered_map>

using namespace std::literals;

class Solution {
   public:
    /*  int lengthOfLongestSubstring2(std::string s) {
          // std::vector<char> temp;
          std::unordered_set<char> buffer;
          std::deque<char> buf;
          int accum = 0;
          int result = 0;
          for (const char& x : s) {
              auto it = buffer.find(x);
              // auto it2 = std::find(buf.begin(), buf.end(), x);
              if (it != buffer.end()) {
                  // если символ был
                  // for (auto it_buf = buf.begin(); it_buf < buf.end(); ++it_buf) {
                  //     if (*it_buf == x) {
                  //         buf.pop_front();
                  //         break;
                  //     }
                  //     buf.pop_front();
                  // }
                  buf.clear();
                  buffer.clear();
                  // if (buf.empty()) {
                  //     ++accum;
                  // } else {
                  //     accum = buf.size();
                  //     accum = buf.size();
                  // }
              }
              buffer.emplace(x);
              buf.emplace_back(x);
              accum = buf.size();
              result = std::max(accum, result);
              // ++accum;
              // if (buffer.size() > accum) {
              // }
          }
          return result;
      }

      // template<typename Iter, >
      // void RecursFanction(Iter begin, Iter end, char ch) {
      void RecursFanction(const std::string& s, char ch, int& res) {
          int result = 0;
          if (s.size() == 0) return;
          for (int i = 0; i + 1 < s.size(); ++i) {
              // auto ssss = s[i];
              auto fin = s.find(s[i], i + 1);
              if (fin != std::string::npos) {
                  RecursFanction(s.substr(i, fin - i), s[i], res);
              } else {
                  res = std::max(static_cast<int>(s.size()), res);
                  // return s.size();
              }
          }
          // return  result;
      }

      int lengthOfLongestSubstring(std::string s) {
          int result = 1;
          RecursFanction(s, s[0], result);
          // for (int i = 0; i + 1 < s.size(); ++i) {
          //     // auto ssss = s[i];
          //     auto fin = s.find(s[i], i + 1);
          //     RecursFanction(s.substr(i, fin - i), s[i]);

          // }
          return result;
      }

      */
    // int lengthOfLongestSubstring(std::string s) {
    //     std::deque<char> buf;
    //     size_t result = (s.size() > 0) ? 1 : 0;
    //     for (int i = 0; i < s.size(); ++i) {
    //         std::unordered_set<char> buf;
    //         buf.emplace(s[i]);
    //         for (int j = i + 1; j < s.size(); ++j) {
    //             auto it = buf.find(s[j]);
    //             if (it != buf.end()) {
    //                 break;
    //             }
    //             buf.emplace(s[j]);
    //             result = std::max(buf.size(), result);
    //         }
    //     }

    // int lengthOfLongestSubstring(std::string s) {
    //     int result = (s.size() > 0) ? 1 : 0;
    //     for (int i = 0; i < s.size(); ++i) {
    //         std::unordered_map<char, int> buf;
    //         int count = 0;
    //         for (int j = i; j < s.size(); ++j) {
    //             auto it = buf.find(s[j]);
    //             if (it != buf.end() && it->second < j) {
    //                 i = it->second;
    //                 break;
    //             }else {
    //                 buf.emplace(s[j], j);
    //                 result = std::max(++count, result);
    //             }
    //         }
    //     }
    //     return result;
    // }

    int lengthOfLongestSubstring(std::string s) {
        // int result = (s.size() > 0) ? 1 : 0;
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