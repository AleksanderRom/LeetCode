#include <vector>
#include <cassert>


class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        auto it_left = nums.begin();
        auto it_right = nums.end();
        std::vector<int> result = {-1,-1};
        int left = 0;
        int right = 0;
        auto pos = it_left;
        while (true) {
            pos = it_left + (it_right - it_left) / 2;
            if (*pos < target) {
                it_left = pos;
            } else if (*pos > target) {
                it_right = pos;
            }
        }
        
    }
};


int main () {
    Solution s;
    {
        std::vector<int> v{0,0,0,1,1,1,2,3,5,7,7,8,8,8,8,8,8,10};
        assert((std::vector<int>{3,4} == s.searchRange(v, 8)));
    }
    {
        std::vector<int> v{5,7,7,8,8,10};
        assert((std::vector<int>{3,4} == s.searchRange(v, 8)));
    }
    {
        std::vector<int> v{5,7,7,8,8,10};
        assert((std::vector<int>{-1,-1} == s.searchRange(v, 6)));
    }
    {
        std::vector<int> v{};
        assert((std::vector<int>{-1,-1} == s.searchRange(v, 0)));
    }
}