#include <algorithm>
#include <cassert>
#include <vector>

class Solution {
   public:
    int threeSumClosest(std::vector<int>& nums, const int target) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int result = 2'147'483'647;
        int dif = result;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < target) {
                    // while(true) {
                    ++j;
                    //     if (j <= k || nums[j] != nums[j - 1]) {
                    //         break;
                    //     }
                    // }
                } else {
                    // while(true) {
                    --k;
                    //     if (j <= k || nums[k] != nums[k + 1]) {
                    //         break;
                    //     }
                    // }
                }
                int buf = std::abs(target - sum);
                if (buf < dif) {
                    dif = buf;
                    result = sum;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    {
        std::vector<int> v{1, 1, 1, 1};
        assert(3 == s.threeSumClosest(v, 0));
    }
    {
        std::vector<int> v{1, 3, 3, 3, 4, 7, 8, 9, 9, 9};
        assert(15 == s.threeSumClosest(v, 15));
    }
    {
        std::vector<int> v{-4, 2, 2, 3, 3, 3};
        assert(0 == s.threeSumClosest(v, 0));
    }
    {
        std::vector<int> v{2, 5, 6, 7};
        assert(15 == s.threeSumClosest(v, 16));
    }
    {
        std::vector<int> v{10, 20, 30, 40, 50, 60, 70, 80, 90};
        assert(60 == s.threeSumClosest(v, 1));
    }
    {
        std::vector<int> v{1, 2, 3, 4};
        assert(9 == s.threeSumClosest(v, 100));
    }
    {
        std::vector<int> v{-1, 2, 1, -4};
        assert(2 == s.threeSumClosest(v, 1));
    }
    {
        std::vector<int> v{0, 0, 0};
        assert(0 == s.threeSumClosest(v, 1));
    }
}