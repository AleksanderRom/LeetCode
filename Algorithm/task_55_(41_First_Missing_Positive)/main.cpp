#include <algorithm>
#include <cassert>
#include <vector>
#include <climits>

using namespace std;

class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            while(nums[i] > 0 &&
                  nums[i] - 1 != i &&
                  nums[i] - 1 < n &&
                  nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i] - 1]);
            }

        }

        for (int i = 0; i < n; ++i) {
            if (nums[i]  != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;

    }

};

                        // Наивный подход

// class Solution {
//    public:
//     int firstMissingPositive(vector<int>& nums) {
//         // sort(nums.begin(), nums.end());
//         sort(nums.begin(), nums.end(), [](auto l, auto r){
//             if (l > 0 && r > 0) return l < r;
//             if (l < 1 && r < 1) return false;
//             return l > r;
//         });
//         if (nums.size() == 1) {
//             return nums[0] == 1 ? 2 : 1;
//         }
//         int result = 1;
//         int prev = INT_MIN;// nums[0];
//         for (auto num : nums) {
//             if (num == prev) {
//                 continue;
//             } else if (num > 0) {
//                 if (result == num) {
//                     ++result;
//                 } else {
//                     return result;
//                 }
//             }
//             prev = num;
//         }
//         return result;
//     }
// };

void Test();
int main() {
    Test();
}

void Test() {
    Solution s;
    {
        vector<int> nums;
        nums.push_back(-2147483648);
        assert(1 == s.firstMissingPositive(nums));
    }
    {
        vector<int> nums{-3, 3, 1, -2, 0, 2, 1, 99999, 4};
        assert(5 == s.firstMissingPositive(nums));
    }
    {
        vector<int> nums{4,3,2, 0};
        assert(1 == s.firstMissingPositive(nums));
    }
    {
        vector<int> nums{100000, 3, 4000, 2, 15, 1, 99999};
        assert(4 == s.firstMissingPositive(nums));
    }
    {
        vector<int> nums{1};
        assert(2 == s.firstMissingPositive(nums));
    }
    {
        vector<int> nums{2};
        assert(1 == s.firstMissingPositive(nums));
    }
    {
        vector<int> nums{0, 2, 2, 1, 1};
        assert(3 == s.firstMissingPositive(nums));
    }
    {
        vector<int> nums{1, 2, 0};
        assert(3 == s.firstMissingPositive(nums));
    }
    {
        vector<int> nums{3, 4, -1, 1};
        assert(2 == s.firstMissingPositive(nums));
    }
    {
        vector<int> nums{7, 8, 9, 11, 12};
        assert(1 == s.firstMissingPositive(nums));
    }
}