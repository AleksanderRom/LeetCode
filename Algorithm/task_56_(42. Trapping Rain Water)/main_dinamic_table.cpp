#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

class Solution {
    int MaxHeight(vector<int>& heigth) {
        int max = 0;
        for (auto num : heigth) {
            max = std::max(max, num);
        }
        return max;
    }

    void UpdateColum(vector<vector<int>>& dt, vector<int>& height, size_t col) {
        int cur_height = height[col];
        for (auto row = 1; row < h; ++row) {
            if (cur_height < prev_max_height && row > cur_height) {

                if (row <= prev_max_height) {
                    dt[row][col + 1] = row - cur_height + dt[row][col];
                } else {
                    dt[row][col + 1] = dt[row - 1][col + 1];
                }
            } else {
                dt[row][col + 1] = dt[row][col];
            }
        }
    }

    int ReturnCountWater(vector<vector<int>>& dt, vector<int>& height) {
        int prev_h = 0;
        size_t i = 0 ;
        for (i = height.size()-1; i > 0; --i) {
            int cur_h = height[i];
            if (cur_h < prev_h) {
                ++i;
                break;
            }
            prev_h = cur_h;
        }

        return dt[height[i]][i];

    }

   public:
    int trap(vector<int>&& height) {
        vector<vector<int>> dt(MaxHeight(height) + 1, vector<int>(height.size() + 1));
        h = dt.size();
        for (size_t col = 0; col < height.size(); ++col) {
            UpdateColum(dt, height, col);
            prev_height = height[col];
            prev_max_height = std::max(prev_max_height, height[col]);
        }
        return ReturnCountWater(dt, height);
    }



   private:
    int prev_max_height = 0;
    int prev_height = 0;
    int h = 0;
};

void Test();

int main() {
    Test();
}

void Test() {

    {
        Solution s;
        int temp = s.trap({2,1,2,0,1});
        int i = 0;
    }
    {
        Solution s;
        auto temp = s.trap({6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3});
        assert(0 == s.trap({6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3}));
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
        assert(37 == s.trap({5, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 5}));
        auto i = 0;
    }
    {
        Solution s;
        assert(6 == s.trap({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}));
    }
}
