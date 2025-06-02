#include <cassert>
#include <vector>

class Solution {
   public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        double med = 0;
        std::vector<int> accum;
        accum.resize(nums1.size() + nums2.size(), 0);
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        if (nums1.empty() && nums2.empty()) {
            return 0;
        } else if (nums1.empty()) {
            std::copy(it2, nums2.end(), accum.begin());
        } else if (nums2.empty()) {
            std::copy(it1, nums1.end(), accum.begin());
        } else {
            for (size_t i = 0; i < accum.capacity(); ++i) {
                if (*it1 < *it2) {
                    accum[i] = *it1++;
                    if (it1 == nums1.end()) {
                        std::copy(it2, nums2.end(), accum.begin() + ++i);
                        break;
                    }
                } else {
                    accum[i] = *it2++;
                    if (it2 == nums2.end()) {
                        std::copy(it1, nums1.end(), accum.begin() + ++i);
                        break;
                    }
                }
            }
        }
        auto size = accum.size();
        if (size % 2 == 0) {
            return (accum[size / 2] + accum[(size / 2) - 1]) * 1.0 / 2;
        }
        return accum[size / 2];
    }
};

int main() {
    Solution s;
    {
        std::vector<int> v1{1, 3};
        std::vector<int> v2{2};
        assert(s.findMedianSortedArrays(v1, v2) == 2);
    }
    {
        std::vector<int> v1{1, 2};
        std::vector<int> v2{3, 4};
        assert(s.findMedianSortedArrays(v1, v2) == 2.5);
    }
    {
        std::vector<int> v1;
        std::vector<int> v2{2, 5, 6};
        assert(s.findMedianSortedArrays(v1, v2) == 5);
    }
}