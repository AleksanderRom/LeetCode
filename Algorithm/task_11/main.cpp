#include <cassert>
#include <vector>

// std::vector<int> num {4782969, 1594323, 531441, 177147, 59049, 19683, 6561, 2187, 729, 243, 81, 27, 9, 3, 1};

class Solution {
    public:
        bool checkPowersOfThree(int n) {
            if (n >= 43'046'721) return false;
            while (true) {
                int ostatok = n % 3; 
                if (ostatok == 2) return false;
                n /= 3;
                if (n == 0) break;
            }
        return true;    
        }
        
    };


int main() {
    Solution s;
    {assert(true == s.checkPowersOfThree(1));} 
    {assert(false == s.checkPowersOfThree(21));} 
    {assert(true == s.checkPowersOfThree(12));} 
    {assert(true == s.checkPowersOfThree(91));} 
}