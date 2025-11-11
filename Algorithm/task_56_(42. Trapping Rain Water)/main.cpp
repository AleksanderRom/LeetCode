#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    int MaxHeight(vector<int>& heigth) {
        int max = 0;
        for (auto num : heigth) {
            max = std::max(max, num);
        }
        return max;
    }
public:
    int trap(vector<int>&& height) {
        int max_prev = 0;
        int water = 0;
        vector<vector<int>> dt(MaxHeight(height), vector<int>(height.size()));
        // vector<vector<int>> dt(1, vector<int>(height.size()));
        // for (auto i = 0; i < height.size(); ++i) {
        //     if (height[i] > max_prev) {
        //         for (auto j = max_prev; j < height[i]; ++j) {
        //             dt.push_back( vector<int>(height.size()));
        //         }
        //         max_prev = height[i];
        //     }
        // }
        return water;
    }
};

void Test();

int main () {

Test();

}

void Test() {
Solution s;
auto res = s.trap({0,1,0,2,1,0,1,3,2,1,2,1});
}

