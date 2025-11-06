#include <algorithm>
#include <cassert>
// #include <unordered_map>
// #include <unordered_set>
#include <vector>

class Solution {
   public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        // optimal
        int n = nums.size();
        std::vector<std::vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum <= target)
                    j++;
                else if (sum > target)
                    k--;
                else {
                    std::vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return 1;
    }
};

int main() {
    Solution s;
    using vec = std::vector<int>;
    {
        vec v{-1, 2, 1, -4};
        assert(1 == s.threeSumClosest(v, 2));
    }
    {
        vec v{0, 0, 0};
        assert(0 == s.threeSumClosest(v, 1));
    }
}
