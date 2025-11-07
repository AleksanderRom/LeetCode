#include <cassert>
#include <string>
#include <vector>

using namespace std::literals;

class Solution {
   public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1)return s;
        std::vector<std::string> buf(numRows);
        const int aa = (s.size() / numRows + 1);
        for (auto& f : buf) {
            f.reserve(aa);
        }
        size_t i = 0;
        bool revers = true;
        for (auto& str : s) {
            if (i == 0) {
                revers = false;
            } else if (i + 1 == numRows)  {
                revers = true;
            }

            buf[i].push_back(std::move(str));
            if (revers == true) {
                --i;
            } else {
                ++i;
            }
        }
        std::string result;
        result.reserve(s.size());
        for (auto& str : buf) {
            result += std::move(str);
        }
        return result;
    }
};

int main() {
    Solution s;
    {
        std::string a("AB");
        std::string b("AB");
        assert(a == s.convert(b, 1));
    }
    {
        std::string a("PINALSIGYAHRPI");
        std::string b("PAYPALISHIRING");
        assert(a == s.convert(b, 4));
    }
    {
        std::string a("PAHNAPLSIIGYIR");
        std::string b("PAYPALISHIRING");
        assert(a == s.convert(b, 3));
    }
}
