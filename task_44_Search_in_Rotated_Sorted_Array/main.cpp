#include <vector>
#include <cassert>




class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int result = -1;
        auto it_l = nums.begin();
        auto it_r = nums.end();
        if (nums.back() == target) {
            return nums.size() - 1;
        }
        if (nums.front() == target) {
            return 0;
        }

        while (true) {
            auto pos = it_l + (it_r - it_l) / 2;
            if (*pos == target) {
                // auto qq = pos - nums.begin();
                return pos - nums.begin();
            }
            if (it_r - it_l == 1) {
                break;
            }

            if (target < nums.back()) {
                if (*pos > nums.back() || *pos < target ) {
                    it_l = pos;
                } else {
                    it_r = pos;
                }
            } else {
                if (*pos < nums.front() || *pos > target) {
                    it_r = pos;
                } else {
                    it_l = pos;
                }
            }

        }

        return result;
    }
};

int main() {
    Solution s;

    {
        std::vector<int> v {3,5,1};
        assert(2 == s.search(v, 1));
    }
    {
        std::vector<int> v {74,76,77,78,79,80,81,82,83,84,85,86,87,1,2,3,4,5,6};
        assert(-1 == s.search(v, 75));
    }
    {
        std::vector<int> v {74,75,76,77,78,79,80,81,82,83,84,85,86,87,1,2,3,4,5,6};
        assert(1 == s.search(v, 75));
    }
    {
        std::vector<int> v {74,75,76,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
        assert(20 == s.search(v, 18));
    }
    {
        std::vector<int> v {74,75,76,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
        assert(1 == s.search(v, 75));
    }
    {
        std::vector<int> v {74,75,76,77,78,79,80,81,82,83,84,85,86,87,1,2,3,4,5,6,7,8};
        assert(14 == s.search(v, 1));
    }
    {
        std::vector<int> v {4,5,6,7,0,1,2};
        assert(4 == s.search(v, 0));
    }
    {
        std::vector<int> v {4,5,6,7,0,1,2};
        assert(-1 == s.search(v, 3));
    }
    {
        std::vector<int> v {1};
        assert(-1 == s.search(v, 0));
    }


}