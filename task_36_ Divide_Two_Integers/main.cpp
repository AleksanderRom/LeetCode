#include <cassert>
#include <vector>
#include <cstdint>
#include <limits>


class Solution {
public:
    int divide(int dividend, int divisor) {
        bool zn = (dividend < 0 ^ divisor < 0) ? false : true;
        long long dd = std::abs(static_cast<long long>(dividend));
        long long dr = std::abs(static_cast<long long>(divisor));
        long long result = 0;
        while (dd >= dr) {
            long long temp = dr;
            long long ml = 1;
            while (dd >= (temp << 1)) {
                temp = temp << 1;
                ml = ml << 1;
            }
            dd -= temp;
            result += ml;
        }

        if (!zn) result = -result;
        if (result > std::numeric_limits<int>::max()) return std::numeric_limits<int>::max();
        if (result < std::numeric_limits<int>::min()) return std::numeric_limits<int>::min();

        return static_cast<int>(result);

    }
};

int main() {
    Solution s;
    // assert(500 == s.divide(-500, -1));
    assert(-2 == s.divide(7, -3));
    assert(2147483647 == s.divide(-2147483648, -1));
    assert(7 == s.divide(23, 3));
    assert(3 == s.divide(10, 3));

}


    //     int dd = dividend < 0 ? -1 : 1;
    //     int dr = divisor < 0 ? -1 : 1;
    //     int64_t chet = 0;
    //     int64_t result = static_cast<int64_t>(dividend) * dd;
    //     divisor *= dr;
    //     while (dividend >= divisor) {
    //         dividend -= divisor;
    //         ++chet;
    //     }
    //     chet = chet * dd * dr;
    //     if (chet >= std::numeric_limits<int>::max()) {
    //         return std::numeric_limits<int>::max();
    //     } else if (chet < std::numeric_limits<int>::min()) {
    //         return std::numeric_limits<int>::min();
    //     }
    //     return chet;
    //     // return chet * dd * dr;
    // }