#include <algorithm>
#include <cassert>
// #include <numeric>
// #include <stack>
#include <string>
#include <vector>


using namespace std;

class Solution {
    int MaxHeight(const vector<int>& heigth) {
        int max = 0;
        for (auto num : heigth) {
            max = std::max(max, num);
        }
        return max;
    }

   public:
    int trap(const vector<int>& height) {
        int water = 0;
        int h = MaxHeight(height);
        for (auto i = 1; i <= h; ++i) {
            bool open = false;
            int pos_open = 0;
            bool pos_closed = false;
            for (auto j = 0; j < height.size(); ++j) {

                if (height[j] < i && open)  {
                    pos_closed = true;
                }

                if (height[j] >= i && pos_closed) {
                    water += j - pos_open - 1;
                }

                if (height[j] >= i) {
                    open = true;
                    pos_open = j;
                } 
                
            }
        }
        return water;
    }

   private:
};

void Test();

int main() {
    Test();
}

void Test() {
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
