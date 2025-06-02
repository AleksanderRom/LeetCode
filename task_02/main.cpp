#include <algorithm>
#include <cassert>
#include <vector>

class Solution {
   public:
    int longestMonotonicSubarray(const std::vector<int>& nums) {
        int straight = 1,
            back = 1,
            buf_straig = 1,
            buf_back = 1;

        for (auto i = 0; i + 1 < nums.size(); ++i) {
            if ((*(nums.begin() + i + 1) - *(nums.begin() + i)) >= 1) {
                ++buf_straig;
            } else {
                straight = std::max(buf_straig, straight);
                buf_straig = 1;
            }

            if ((*(nums.begin() + nums.size() - 2 - i) - *(nums.begin() + nums.size() - 1 - i)) >= 1) {
                ++buf_back;
            } else {
                back = std::max(buf_back, back);
                buf_back = 1;
            }
        }
        straight = std::max(buf_straig, straight);
        back = std::max(buf_back, back);
        return std::max(straight, back);
    }
};

int main() {
    Solution x;
    {
        std::vector<int> a{1, 4, 5, 3, 2};
        assert(3 == x.longestMonotonicSubarray(a));
    }
    {
        std::vector<int> a{1, 4, 3, 3, 2};
        assert(2 == x.longestMonotonicSubarray(a));
    }
    {
        assert(1 == x.longestMonotonicSubarray(std::vector<int>{3, 3, 3, 3}));
    }
    {
        assert(3 == x.longestMonotonicSubarray(std::vector<int>{3, 2, 1}));
    }
    {
        assert(2 == x.longestMonotonicSubarray(std::vector<int>{1, 3}));
    }
    {
        assert(2 == x.longestMonotonicSubarray(std::vector<int>{1, 1, 5}));
    }
}
