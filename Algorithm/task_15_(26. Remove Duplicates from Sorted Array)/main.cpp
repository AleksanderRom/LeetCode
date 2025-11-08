#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto it = std::unique(nums.begin(), nums.end());
        return (it - nums.begin());
    }
};