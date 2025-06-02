#include <cassert>
#include <string>
#include <vector>

using namespace std::literals;

const std::vector<char> v2{'a', 'b', 'c'};
const std::vector<char> v3{'d', 'e', 'f'};
const std::vector<char> v4{'g', 'h', 'i'};
const std::vector<char> v5{'j', 'k', 'l'};
const std::vector<char> v6{'m', 'n', 'o'};
const std::vector<char> v7{'p', 'q', 'r', 's'};
const std::vector<char> v8{'t', 'u', 'v'};
const std::vector<char> v9{'w', 'x', 'y', 'z'};

class Solution {
   public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.size() == 0) return {};
        std::vector<std::vector<char>> num;

        for (auto str : digits) {
            switch (str - 48) {
                case 2:
                    num.push_back(v2);
                    break;
                case 3:
                    num.push_back(v3);
                    break;
                case 4:
                    num.push_back(v4);
                    break;
                case 5:
                    num.push_back(v5);
                    break;
                case 6:
                    num.push_back(v6);
                    break;
                case 7:
                    num.push_back(v7);
                    break;
                case 8:
                    num.push_back(v8);
                    break;
                case 9:
                    num.push_back(v9);
            }
            // if (str)
            // num.push_back(str - 48);
        }

        int size = 1;
        for (auto& str : num) {
            size *= str.size();
        }
        std::vector<std::string> result(size);
        int step = size;
        for (int i = 0; i < num.size(); ++i) {
            int index = 0;
            int j = 0;
            step /= num[i].size();
            while (index < size) {
                for (auto ch : num[i]) {
                    while (j < step) {
                        result[index++].push_back(ch);
                        ++j;
                    }
                    j = 0;
                }
            }
        }
        return result;
    }
};

    // bool RecursFanction(std::vector<std::string>& result, std::vector<char> ch);

int main() {
    Solution s;
    using str = std::vector<std::string>;
    assert((str{} == s.letterCombinations("")));
    assert((str{"w"s, "x"s, "y"s, "z"s} == s.letterCombinations("9")));
    // assert((str{"aa"s, "ab"s, "ac"s, "ba"s, "bb"s, "bc"s, "ca"s, "cb"s, "cc"s} == s.letterCombinations("4259")));
    assert((str{"ad"s, "ae"s, "af"s, "bd"s, "be"s, "bf"s, "cd"s, "ce"s, "cf"s} == s.letterCombinations("23")));
    assert((str{"aa"s, "ab"s, "ac"s, "ba"s, "bb"s, "bc"s, "ca"s, "cb"s, "cc"s} == s.letterCombinations("22")));
}