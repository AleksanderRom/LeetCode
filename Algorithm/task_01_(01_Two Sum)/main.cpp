#include <vector>
#include <set>
#include <algorithm>
#include <iterator>
#include <cassert>


class Solution {
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target) {
        std::vector<int> new_nums(nums.begin(), nums.end());
        std::sort(new_nums.begin(), new_nums.end());
        int a = 0;
        int b = 0;
        for (auto it = new_nums.begin(); it != new_nums.end(); ++it) {
            auto iter_b = std::lower_bound(it + 1 , new_nums.end(), target - *it);
            if (iter_b != new_nums.end() && *iter_b + *it == target){
                    a = *it;
                    b = *iter_b;
                    break;
            }
        }


        if (a != b) {
           auto p_a = std::find(nums.begin(), nums.end(), a);
           auto p_b = std::find(nums.begin(), nums.end(), b);
           auto aa = std::distance(nums.begin(), p_a);
           auto bb = std::distance(nums.begin(), p_b);

           return {static_cast<int>(aa), static_cast<int>(bb)};
        } else {
           auto p_a = std::find(nums.begin(), nums.end(), a);
           auto p_b = std::find(p_a + 1, nums.end(), b);
           auto aa = std::distance(nums.begin(), p_a);
           auto bb = std::distance(nums.begin(), p_b);

           return {static_cast<int>(aa), static_cast<int>(bb)};

        }
    return {0, 0};
    }
};

int main() {
 Solution x;
 {
 std::vector<int> nums {2, 7, 7, 11, 15};
 std::vector<int> xx = x.twoSum(nums, 9);
    assert(xx[0] == 0);
    assert(xx[1] == 1);
    // assert(xx == {1, 0});
 }
 {
 auto xx = x.twoSum(std::vector<int>{3, 2, 4}, 6);
    assert(xx[0] == 1);
    assert(xx[1] == 2);
 }
 {
 auto xx = x.twoSum(std::vector<int>{3, 3}, 6);
    assert(xx[0] == 0);
    assert(xx[1] == 1);
    int i = 0;
 }

  {
 auto xx = x.twoSum(std::vector<int>{-3, 4, 3, 90}, 0);
    assert(xx[0] == 0);
    assert(xx[1] == 2);
    int i = 0;
 }


//  auto xx = twoSum(nums, 9);
//     int i = 0;
}