#include <algorithm>
#include <cassert>
#include <vector>

class Solution {
   public:
    void nextPermutation(std::vector<int>& nums) {
        if (nums.size() < 2) return;
        auto suffix = nums.rbegin();
        while (true) {
            auto next = suffix + 1;
            if ((next) == nums.rend()) {
                // break;
                std::reverse(nums.begin(), nums.end());
                // std::sort(nums.begin(), nums.end());
                return;
            } 
            if ( *(next) < *suffix) {
                ++suffix;
                break;
            }
            ++suffix;
        }
        // ++suffix;
        auto it_swap = nums.rbegin();
        while (true) {
            if (*it_swap > *(suffix)) {
                break;
            }
            ++it_swap;
        }
        std::swap(*(suffix), *it_swap);
        std::sort(nums.rbegin(), (suffix), [](int lsh, int rhs){return rhs < lsh;});
    }
};

int main() {
    Solution s;
    {
        std::vector<int> v{1,3,2};
        s.nextPermutation(v);
        assert((std::vector<int>{2,1,3} == v));
    }
    {
        std::vector<int> v{1,2};
        s.nextPermutation(v);
        assert((std::vector<int>{2,1} == v));
    }
    {
        std::vector<int> v{};
        s.nextPermutation(v);
        assert((std::vector<int>{} == v));
    }
    {
        std::vector<int> v{1};
        s.nextPermutation(v);
        assert((std::vector<int>{1} == v));
    }
    {
        std::vector<int> v{3, 2, 1};
        s.nextPermutation(v);
        assert((std::vector<int>{1, 2, 3} == v));
    }
    {
        std::vector<int> v{0, 1, 2, 5, 3, 3, 0};
        s.nextPermutation(v);
        assert((std::vector<int>{0, 1, 3, 0, 2, 3, 5} == v));
    }
    {
        std::vector<int> v{1, 2, 3};
        s.nextPermutation(v);
        assert((std::vector<int>{1, 3, 2} == v));
    }
    {
        std::vector<int> v{1, 1, 5};
        s.nextPermutation(v);
        assert((std::vector<int>{1, 5, 1} == v));
    }
}