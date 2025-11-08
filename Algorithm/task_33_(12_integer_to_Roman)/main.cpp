#include <cassert>
#include <string>
#include <vector>

static char IdentSimbolFive(int size) {
    if (size == 3) {
        return 'D';
    } else if (size == 2) {
        return 'L';
    }
    return 'V';
}

static char IdentSimbol(int size) {
    if (size == 4) {
        return 'M';
    } else if (size == 3) {
        return 'C';
    } else if (size == 2) {
        return 'X';
    }
    return 'I';
}

class Solution {
   public:
    std::string intToRoman(int num) {
        std::vector<int> rom;
         rom.reserve(4);
        while (num != 0) {
            rom.push_back(num % 10);
            num /= 10;
        }
        int size = rom.size();
        std::string result;
        // result.reserve(size * 4);
        result.reserve(15);

        for (int i = rom.size() - 1; i >= 0; --i) {
            char simbol = IdentSimbol(size--);
            if (rom[i] == 9) {
                result.push_back(simbol);
                result.push_back(IdentSimbol(size + 2));

            } else if (rom[i] == 4) {
                result.push_back(simbol);
                result.push_back(IdentSimbolFive(size + 1));

            } else if (rom[i] == 5) {
                result.push_back(IdentSimbolFive(size + 1));

            } else if (rom[i] > 5) {
                int j = rom[i] - 5;

                result.push_back(IdentSimbolFive(size + 1));
                while (j != 0) {
                    result.push_back(simbol);
                    --j;
                }

            } else {
                int j = rom[i];
                while (j != 0) {
                    result.push_back(simbol);
                    --j;
                }
            }
        }
        // int i = 0;
        return result;
    }
};

int main() {
    Solution s;
    assert("MMMCMXCIX" == s.intToRoman(3999));
    assert("MCMXCIV" == s.intToRoman(1994));
    assert("LVIII" == s.intToRoman(58));
    assert("MMMDCCXLIX" == s.intToRoman(3749));
    assert("M" == s.intToRoman(1000));
    assert("I" == s.intToRoman(1));
    assert("II" == s.intToRoman(2));
    assert("III" == s.intToRoman(3));
    assert("IV" == s.intToRoman(4));
    assert("V" == s.intToRoman(5));
    assert("VI" == s.intToRoman(6));
    assert("VII" == s.intToRoman(7));
    assert("VIII" == s.intToRoman(8));
    assert("IX" == s.intToRoman(9));
    assert("X" == s.intToRoman(10));
    assert("XI" == s.intToRoman(11));
}