// #include <cassert>
#include <iostream>
// #include <cstdint>

class Solution {
   public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int a = 1, b = 2;
        int result = 0;
        for (int i = 2; i < n; ++i) {
            result = a + b;
            a = std::max(a, b);
            b = result; 
        }
        return result;
    }
};

// void Tests();
int main() {
    // Tests();
    int n = 0;

    std::cin >> n;
    Solution s;

    std::cout << s.climbStairs(n) << std::endl;
    return 0;
}

// void Tests() {
//     Solution s;
//     assert(5 == s.climbStairs(4));
//     assert(3 == s.climbStairs(3));
//     assert(2 == s.climbStairs(2));
//     assert(8 == s.climbStairs(5));
//     for (auto i = 0; i < 100; ++i) {
//         std::cout << "i = "<< i << ": " << s.climbStairs(i) << std::endl;
//     }
// }