#include <cassert>
#include <vector>

using namespace std;

class Solution {

   public:
    int trap(const vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int max_left = height[left];
        int max_right = height[right];
        int water = 0;
        while (left != right) {
            if (max_left < max_right ) {
                ++left;
                max_left = max(max_left, height[left]);
                water += max_left - height[left];
            }else {
                --right;
                max_right = max(max_right, height[right]);
                water += max_right - height[right];
            }

        }
        return water;
    }

};

void Test();

int main() {
    Test();
}

void Test() {
    {
        Solution s;
        assert(3 == s.trap({8, 5, 7, 7, 4, 5, 1,0}));
    }
    {
        Solution s;
        assert(15 == s.trap({4, 0, 2, 1, 2, 0, 4}));
    }
    {
        Solution s;
        assert(37 == s.trap({5, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 5}));
    }
    {
        Solution s;
        assert(6 == s.trap({3, 1, 2, 0, 3}));
    }
    {
        Solution s;
        assert(2 == s.trap({2, 1, 2, 0, 1}));
    }

    {
        Solution s;
        assert(26 == s.trap({0, 1, 0, 3, 0, 5, 0, 1, 0, 3, 4, 0, 6}));
    }

    {
        Solution s;
        auto temp = s.trap({6, 4, 2, 0, 3, 2, 0, 3, 1, 4, 5, 3, 2, 7, 5, 3, 0, 1, 2, 1, 3, 4, 6, 8, 1, 3});
        assert(83 == s.trap({6, 4, 2, 0, 3, 2, 0, 3, 1, 4, 5, 3, 2, 7, 5, 3, 0, 1, 2, 1, 3, 4, 6, 8, 1, 3}));
    }
    {
        Solution s;
        assert(0 == s.trap({0, 1}));
    }
    {
        Solution s;
        assert(0 == s.trap({5, 1}));
    }
    {
        Solution s;
        assert(1 == s.trap({10, 9, 10}));
    }
    {
        Solution s;
        assert(9 == s.trap({10, 1, 10}));
    }
    {
        Solution s;
        assert(10 == s.trap({10, 0, 10}));
    }
    {
        Solution s;
        assert(6 == s.trap({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}));
    }
    {
        Solution s;
        assert(37 == s.trap({5, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 5}));
    }
}
