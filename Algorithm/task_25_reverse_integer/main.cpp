// #include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>
#include <limits>

// const static int MAX = std::numeric_limits<int>::max();
// const static int MIN = std::numeric_limits<int>::min();

class Solution {
   public:
    int reverse(int x) {
        // переменная для срезки последних нулей
        // bool first = true;
        int result = 0;
        // INT_MAX
        // std::vector<int> buf;
        while (x != 0) {
            int i = x % 10;
            x /= 10;
            // if (first && i == 0) {
            //     continue;
            // }

            // first = false;
            if(result > INT_MAX / 10 || result < INT_MIN / 10) {
                return 0;
            }
            // buf.push_back(i);
            result = result * 10 + i;
        }
        // восстановление в обратном поряде
        // int size = buf.size() - 1;
        // for (int i = 0; i <= size; ++i) {
        //     int ggg = std::pow(10, size - i);
        //     x += buf[i] * std::pow(10, size - i);
        // }

        // bool sign2 = (x < 0) ? true : false;
        // if (sign2 == sign) {
        //     return x;
        // }
        return result;

    }
};

int main() {
    Solution s;
    
    assert(1 == s.reverse(100000000));
    assert(-3021 == s.reverse(-1203));
    assert(0 == s.reverse(1'534'236'469));
    assert(321 == s.reverse(1230));
    assert(0 == s.reverse(0));
    assert(-321 == s.reverse(-12300));
    assert(-1 == s.reverse(-100000000));
    assert(987'654'321 == s.reverse(1'234'567'890));

}