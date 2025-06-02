#include <cassert>
#include <limits>
#include <string>
#include <cstdint>

using namespace std::literals;

bool CheckChar(char ch) {
    return (ch < '0' || ch > '9');
}

class Solution {
    int max = std::numeric_limits<int>::max();
    int min = std::numeric_limits<int>::min();

   public:
    int myAtoi(std::string s) {
        bool first = true;
        bool sign = true;  // true - плюс, false - минус

        int64_t result = 0;
        for (const auto& ch : s) {
            if (first) {
                if (ch == ' ') {
                    continue;
                } else if (ch == '+') {
                    first = false;  // закончили первичный парсинг
                    continue;
                } else if (ch == '-') {
                    first = false;
                    sign = false;
                    continue;
                } else if (CheckChar(ch)) {
                    return 0;
                }

            } else if (CheckChar(ch)) {
                break;
            }
            first = false;
            
            result = result * 10 + ch - 48;

        if (sign && result > std::numeric_limits<int>::max()) {
            return std::numeric_limits<int>::max();
        } else if (!sign && -1*result < std::numeric_limits<int>::min()) {
            return std::numeric_limits<int>::min();
        }
        }

        if (!sign) {
            result *= -1;
        }

        return result;
    }
};

int main() {
    Solution s;
    // int x = std::stoi("dfs"s);
    assert(-2'147'483'648 == s.myAtoi("-2147483648"s));
    assert(2'147'483'647 == s.myAtoi("20000000000000000000"s));
    assert(2'147'483'647 == s.myAtoi("21474836460"s));
    assert(2'147'483'646 == s.myAtoi("+2147483646"s));
    assert(-2'147'483'647 == s.myAtoi("-2147483647"s));
    assert(2'147'483'647 == s.myAtoi("+2147483648"s));
    assert(0 == s.myAtoi("words and 987"s));
    assert(-42 == s.myAtoi(" -42"s));
    assert(-42 == s.myAtoi(" -0042"s));
    assert(1337 == s.myAtoi("1337c0d3"s));
    assert(0 == s.myAtoi("0-1"s));
    assert(42 == s.myAtoi("42"s));
    assert(42 == s.myAtoi("  042"s));
    assert(420 == s.myAtoi("  0420"s));
    auto dd = s.myAtoi("+2147483648"s);
}