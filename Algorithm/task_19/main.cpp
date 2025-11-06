#include <algorithm>
#include <cassert>
// #include <deque>
// #include <map>
#include <string>
#include <vector>
// #include <unordered_set>
// #include <unordered_map>

using namespace std::literals;

class Solution {
   public:
    int removeElement(std::vector<int>& nums, int val) {
        auto it_start = nums.begin();
        while (nums.end() != it_start) {
            if (*it_start == val) {
                std::swap(*(nums.end() - 1), *it_start);
                nums.resize(nums.size() - 1);
            } else {
                ++it_start;
            }
        }
        return nums.size();
    }
};

int main() {
    Solution s;
    // s
    {
        std::vector<int> a{1};
        assert(0 == s.removeElement(a, 1));
    }
    {
        std::vector<int> a{3, 2, 2, 3};
        assert(2 == s.removeElement(a, 3));
    }
    {
        std::vector<int> a{0, 1, 2, 2, 3, 0, 4, 2};
        assert(5 == s.removeElement(a, 2));
    }
    {
        std::vector<int> a{};
        assert(0 == s.removeElement(a, 2));
    }
}