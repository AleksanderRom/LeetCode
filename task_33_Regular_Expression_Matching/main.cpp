#include <cassert>
#include <string>
#include <vector>

class Solution {
   public:  

    bool isMatch(std::string str, std::string reg) {
         size_t row = str.size(); //строки
         size_t col = reg.size(); //столбцы
        std::vector<std::vector<bool>> dp(row + 1, std::vector<bool>(col + 1, false));
        dp[0][0] = true;
        //инициализация
        for (int j = 1; j <= col; ++j) {
            if (reg[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        //заполнение
        for (int i = 1; i <= row; ++i) {//проход по строкам
            for (int j = 1; j <= col; ++j) { //проход по столбцам
                if (str[i - 1] == reg[j - 1] || reg[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (reg[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2]; //пропускаем a*
                    if (reg[j - 2] == str[i - 1] || reg[j - 2] == '.') {//предыдущий символ шаблона совпадает с текущим сиволом строки
                        dp[i][j] = dp[i][j] || dp[i - 1][j]; // сравниваем с верхним значением (см. табл)
                    }
                }
            }
        }
        return dp[row][col];
    }

};

#include <iostream>
int main() {
    Solution s;
    // assert(true == s.isMatch("abcdef", "a.a"));
    // assert(true == s.isMatch("aba", "a.a"));
    // mississppi
    assert(true == s.isMatch("a", "ab*a"));
    assert(true == s.isMatch("aab", "c*a*b"));
    assert(true == s.isMatch("aaan", "a*n"));
    assert(true == s.isMatch("aaa", "a*"));
    assert(true == s.isMatch("", ""));
    assert(false == s.isMatch("asa", "a*"));
    assert(true == s.isMatch("aaa", "aaa"));
    assert(true == s.isMatch("abc", "abc"));
    assert(false == s.isMatch("aa", "aaa"));
    
    assert(true == s.isMatch("aaa", ".*"));
    assert(false == s.isMatch("mississippi", "mis*is*p*."));
    assert(true == s.isMatch("aba", "a.a"));
    assert(true == s.isMatch("abcdeae", "a.*e"));
    assert(false == s.isMatch("aba", "."));
    assert(true == s.isMatch("aba", "..."));
    assert(true  == s.isMatch("aba", ".*"));
    assert(true == s.isMatch("abbcba", "a.*a"));
    assert(true == s.isMatch("abbba", "a.*a"));






    std::cout << "OK" << std::endl;
    int i = 0;
}

/*
while () {
    buf = reg[index_r];

    if(buf == '*') {
        buf = reg[--index_r];
    } else if (bif == '.') {
        bif = str[indx_s];
   }

    if (str[indx_s] != buf) {
        return false;
        else {
        //ввле за пределы мпссива
            ++indx_s;
            ++indx_r;
            continue;
        }
    }
    return true;
}
*/

/*
class Solution {
   public:
    bool isMatch(std::string str, std::string reg) {
        return isMatch_recurs(str, reg);
    }

    bool isMatch_recurs(std::string str, std::string reg) {
        int indx_s = 0;
        int indx_r = 0;
        auto it_s = str.begin();
        auto it_r = reg.begin();
        bool star = false;

        char buf;
        while (it_s != str.end() || it_r != reg.end()) {
            buf = *it_r;
            if (*it_r == '.') {
                buf = *it_s;
            }

            if (*(it_r - 1) == '.' && *it_r == '*') {
                ++it_r;

                while (it_s != str.end()) {
                    std::string s(it_s, str.end());
                    std::string r(it_r, reg.end());
                    if (!isMatch_recurs(s, r)) {
                        ++it_s;
                    } else {
                        buf = *it_s;
                        break;
                    }
                }
                star = false;

            } else if (*it_r == '*') {
                buf = *(it_r - 1);
                while (*it_s == buf) {
                    ++it_s;
                }
                ++it_r;
                star = false;
            }

            if (it_s == str.end() || it_r == reg.end()) break;

            if (*it_r != '.') {
                buf = *it_r;
            }
            
            if (star == true) return false;
            if (*it_s != buf) {
                star == true;
                // return false;
            }
                ++it_s;
                ++it_r;
        }

        if (it_s == str.end() && (it_r == reg.end())) {
            return true;
        }
        return false;
    }
};
*/