
#include <cassert>
#include <cmath>
#include <vector>
#include <limits>

class Solution {
   public:
    int reverse(int x) {
        int result = 0;
        while (x != 0) {
            int i = x % 10;
            x /= 10;

            if(result > INT_MAX / 10 || result < INT_MIN / 10) {
                return 0;
            }
            result = result * 10 + i;
        }
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