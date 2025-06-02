#include <algorithm>
#include <cassert>
// #include <unordered_map>
// #include <unordered_set>
#include <vector>
#include <cstdint>

class Solution {
   public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& n, int target) {
        std::sort(n.begin(), n.end());
        size_t count = n.size();
        if (count < 4) return {};
        std::vector<std::vector<int>> result;

        for (int i = 0; i < count - 3; ++i) {
            if (i > 0 && n[i] == n[i - 1]) continue;
            for (int j = i + 1; j < count - 2; ++j) {
                if (j > i + 1 && n[j] == n[j -1]) continue;
                int l = j + 1;
                int r = count - 1;
                while (l < r) {
                    int64_t sum = int64_t(n[i]) + int64_t(n[j]) + int64_t(n[l]) + int64_t(n[r]);
                    if (sum < target) {
                        ++l;
                    } else if (sum > target) {
                        --r;
                    } else {
                        result.push_back(std::vector<int>{n[i], n[j], n[l], n[r]});
                        while (l < r && n[l] == n[l + 1]) {
                            ++l;
                        }
                        while (l < r && n[r] == n [r - 1]) {
                            --r;
                        }
                        --r;
                        ++l;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    using vec = std::vector<int>;
    {
        vec v{2, 2, 2, 2, 2};
        assert((std::vector<vec>{vec{2, 2, 2, 2}} == s.fourSum(v, 8)));
    }
    {
        vec v{-3, -2, -1, 0, 0, 1, 2, 3};
        assert((std::vector<vec>{{-3, -2, 2, 3}, {-3, -1, 1, 3}, 
                                {-3, 0, 0, 3}, {-3, 0, 1, 2}, 
                                {-2, -1, 0, 3}, {-2, -1, 1, 2}, 
                                {-2, 0, 0, 2}, {-1, 0, 0, 1}} == s.fourSum(v, 0)));
    }
    {
        vec v{1000000000,1000000000,1000000000,1000000000};
        assert((std::vector<vec>{vec{0, 0, 0, 0}} == s.fourSum(v, 0)));
    }
    {
        vec v{0, 0, 0, 0};
        assert((std::vector<vec>{vec{0, 0, 0, 0}} == s.fourSum(v, 0)));
    }
    {
        vec v{};
        assert((std::vector<vec>{} == s.fourSum(v, 0)));
    }
    {
        vec v{1, 0, -1, 0, -2, 2};
        assert((std::vector<vec>{vec{-2, -1, 1, 2}, vec{-2, 0, 0, 2}, vec{-1, 0, 0, 1}} == s.fourSum(v, 0)));
    }
    {
        vec v{0, 0, 0};
        // assert(0 == s.threeSumClosest(v, 1));
    }
}
