#include <algorithm>
#include <cassert>
// #include <unordered_map>
// #include <unordered_set>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& n, int target) {
        std::sort(n.begin(), n.end());
        size_t count = n.size();
        if (count < 4) return {};
        std::vector<std::vector<int>> result;

        for (int i = 0; i < count - 3; ++i) {
            for (int j = i + 1; j < count - 2; ++j) {
                int l = j + 1;
                int r = count - 1;
                while (l < r) {
                    int sum = n[i] + n[j] + n[l] + n[r];
                    if (sum < target) {
                        ++l;
                        continue;
                    } else if (sum > target) {
                        --r;
                        continue;
                    } else {
                        result.push_back(std::vector{n[i], n[j], n[l], n[r]});
                        break;
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
        vec v{0,0,0,0};
        assert((std::vector<vec>{vec{0,0,0,0}} == s.fourSum(v, 0)));
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
