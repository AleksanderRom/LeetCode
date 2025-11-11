#include <cassert>
#include <string>
#include <vector>
// #include <cmath>

using namespace std;

class Solution {
   public:
    // int StringToInterger(const string& num) {
    //     int buf = 0;
    //     int n = num.size();
    //     for (int i = 0; i < n; ++i) {
    //         buf *= 10;
    //         buf += (num[i] - 48);
    //     }
    //     return buf;
    // }

    int ChToInt(char ch) {
        return ch - 48;
    }

    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        if (n2 > n1) {
            std::swap(num1, num2);
            std::swap(n1, n2);
        }
        vector<vector<int>> dp(n2, vector<int>(n1));

        for (int i = 0; i < n2; ++i) {
            for (int j = 0; j < n1; ++j) {
                auto in1 = ChToInt(num1[n1 - i - 1]);
                auto in2 = ChToInt(num2[n2 - j - 1]);
                dp[i][j] = in1 * in2;
            }
        }

        string result;
        for (int i = 0; i < n1 + n2 - 1; ++i) {
            int buf = 0;

            for (int j = 0, k = i; j < i + 1; ++j, --k) {
                if (j >= n1 || k >= n2) {
                    continue;
                }
                buf += dp[j][k];
            }

            result.push_back(GetCh(buf) + 48);
        }
        if (remains_ > 0) {
            result.push_back(remains_ + 48);
        }
        remains_ = 0;
        return string(result.rbegin(), result.rend());
    }

    char GetCh(int buf) {
        buf += remains_;
        char ch = 0;

        if (buf >= 10) {
            remains_ = buf / 10;
            return buf % 10;
        }
        remains_ = 0;
        return ch = buf;
    }

   private:
    int remains_ = 0;
};

void Test();

int main() {
    Test();
}

void Test() {
    Solution s;
    assert("492" == s.multiply("123", "4"));
    auto ddd = s.multiply("123456789", "987654321");
    assert("121932631112635269"s == s.multiply("123456789", "987654321"));
    // assert(32 == s.StringToInterger("32"));
    // assert(132 == s.StringToInterger("132"));
    // assert(0 == s.StringToInterger("0"));
    // assert(0 == s.StringToInterger(""));

    auto t = s.multiply("2", "3");
    assert("6" == s.multiply("2", "3"));
    assert("56088" == s.multiply("123", "456"));
    assert("492" == s.multiply("4", "123"));
}