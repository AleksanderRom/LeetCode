#include <cassert>
#include <vector>

class Solution {
   public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }
        auto it_left_start = nums.begin();
        auto it_left_end = nums.end();
        auto it_right_start = nums.begin();
        auto it_right_end = nums.end();
        // std::vector<int> result = {-1, -1};
        // int left = 0;
        // int right = 0;
        auto pos_l = it_left_start;
        auto pos_r = it_right_end;
        while (true) {
            pos_l = it_left_start + (it_left_end - it_left_start) / 2;
            pos_r = it_right_start + (it_right_end - it_right_start) / 2;
            auto left = pos_l - nums.begin();
            auto right = pos_r - nums.begin();
            if (it_left_end - it_left_start < 2 && it_right_end - it_right_start < 2) {
                if (*pos_r != target) {
                    return {-1, -1};
                }
                int n = (*pos_l == target ? 0 : 1);
                return {static_cast<int>(pos_l - nums.begin()) + n, static_cast<int>(pos_r - nums.begin())};
            }
            ///////////////////////
            if (*pos_l < target) {
                it_left_start = pos_l;
            } else if (*pos_l >= target) {
                it_left_end = pos_l;
            }
            ///////////////////////
            if (*pos_r <= target) {
                it_right_start = pos_r;
            } else if (*pos_r > target) {
                it_right_end = pos_r;
            }
        }
    }
};

int main() {
    Solution s;
    {
        std::vector<int> v{1, 1, 2};
        assert((std::vector<int>{0, 1} == s.searchRange(v, 1)));
    }
    {
        std::vector<int> v{0, 0, 0, 1, 1, 1, 2, 3, 5, 7, 7, 8, 8, 8, 8, 8, 8};
        assert((std::vector<int>{0, 2} == s.searchRange(v, 0)));
    }
    {
        std::vector<int> v{5, 7, 7, 8, 8, 10};
        assert((std::vector<int>{-1, -1} == s.searchRange(v, 6)));
    }
    {
        std::vector<int> v{5, 7, 8, 8, 10};
        assert((std::vector<int>{1, 1} == s.searchRange(v, 7)));
    }
    {
        std::vector<int> v{0, 0, 0, 1, 1, 1, 2, 3, 5, 7, 7, 8, 8, 8, 8, 8, 8, 10};
        assert((std::vector<int>{11, 16} == s.searchRange(v, 8)));
    }
    {
        std::vector<int> v{5, 7, 7, 8, 8, 10};
        assert((std::vector<int>{3, 4} == s.searchRange(v, 8)));
    }
    {
        std::vector<int> v{};
        assert((std::vector<int>{-1, -1} == s.searchRange(v, 0)));
    }
    {
        std::vector<int> v{0, 1, 2, 8, 8, 8, 8, 8, 8};
        assert((std::vector<int>{3, 8} == s.searchRange(v, 8)));
    }
}