#include <cassert>
#include <deque>
#include <vector>

class Solution {
   public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        for (auto it = digits.rbegin(); it < digits.rend(); ++it) {
            if (*it < 9) {
                ++(*it);
                return digits;
            } else {
                *it = 0;
            }
        }
        //если нужно увеличить
        std::vector<int> result(digits.size() + 1, 1);  
        std::move(digits.begin(), digits.end(), result.begin() + 1);
        return result;
    }
};

int main() {
    Solution s;
    {
    std::vector<int> v{9, 9};
    assert((std::vector<int>{1, 0, 0} == s.plusOne(v)));
    }
    {
    std::vector<int> v{1, 2, 9};
    assert((std::vector<int>{1, 3, 0} == s.plusOne(v)));
    }
    {
    std::vector<int> v{1, 2, 3};
    assert((std::vector<int>{1, 2, 4} == s.plusOne(v)));
    }
}