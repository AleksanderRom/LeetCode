#include <cassert>
#include <string>
#include <vector>

using namespace std;

// 1,5,6,7
class Solution {
   public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) {
            return {};
        }

        vector<string> result;
        int start = nums[0];
        int prev = nums[0];

        for (const auto& num : nums) {
            if (num == start) continue;
            if (num != prev + 1) {
                result.emplace_back(ToString(start, prev));
                prev = start = num;
            } else {
                prev = num;
            }
        }

        result.emplace_back(ToString(start, prev));

        return result;
    }

    string ToString(int a, int b) {
        if (a == b) {
            return string{to_string(a)};
        }
        return string{to_string(a) + "->" + to_string(b)};
    }
};

int main() {
    Solution s;
    {
        vector<int> nums{0, 1, 2, 4, 5, 7};
        assert((vector<string>{"0->2", "4->5", "7"} == s.summaryRanges(nums)));
    }
    {
        vector<int> nums{0, 2, 3, 4, 6, 8, 9};
        assert((vector<string>{"0", "2->4", "6", "8->9"} == s.summaryRanges(nums)));
    }
    {
        vector<int> nums{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        assert((vector<string>{"0->9"} == s.summaryRanges(nums)));
    }
    {
        vector<int> nums{0};
        assert((vector<string>{"0"} == s.summaryRanges(nums)));
    }
    {
        vector<int> nums{};
        assert((vector<string>{} == s.summaryRanges(nums)));
    }
}