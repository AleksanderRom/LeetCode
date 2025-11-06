#include <vector>
#include <iostream>
#include <cassert>
#include <map>


void Addmap(std::map<int, int>& result, std::vector<std::vector<int>>& nums1){
    for (auto n : nums1) {
        int a = n[0];
        int b = n[1];
        result[n[0]] += n[1];
     }
}

class Solution {
    public:
        std::vector<std::vector<int>> mergeArrays(std::vector<std::vector<int>>& nums1, std::vector<std::vector<int>>& nums2) {
            std::map<int, int> res;
            Addmap(res, nums1);
            Addmap(res, nums2);
            std::vector<std::vector<int>> result;
            result.reserve(res.size());
              for(auto [left, right] : res) {
                  result.push_back({left, right});
              }  
             return result;
        }
    };

int main() {
    Solution s;
    {
        std::vector<std::vector<int>> a{{1, 2},{2, 3},{4, 5}};
        std::vector<std::vector<int>> b{{1, 4},{3, 2},{4, 1}};
        std::vector<std::vector<int>> r{{1, 6},{2, 3},{3, 2},{4, 6}};
        assert(r == s.mergeArrays(a, b));
    }
    {
        std::vector<std::vector<int>> a{{2, 4},{3, 6},{5, 5}};
        std::vector<std::vector<int>> b{{1, 3},{4, 3}};
        std::vector<std::vector<int>> r{{1, 3},{2, 4},{3, 6},{4, 3},{5, 5}};
        assert(r == s.mergeArrays(a, b));
    }

}