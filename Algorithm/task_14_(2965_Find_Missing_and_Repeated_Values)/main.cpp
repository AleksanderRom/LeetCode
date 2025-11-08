#include <vector>
#include <cassert>
#include <algorithm>

class Solution {
    public:
        std::vector<int> findMissingAndRepeatedValues(std::vector<std::vector<int>>& grid) {
            std::vector<int> temp (grid.size() * grid[0].size() + 1);
            std::fill(temp.begin() , temp.end(), 0);
            for (size_t i = 0; i < grid.size(); ++i) {
                for (size_t j = 0; j < grid[0].size(); ++j) {
                    ++temp[grid[i][j]];
                }
            }
            int a = 0, b = 0;
            for (size_t i = 1; i < temp.size(); ++i) {
                if (temp[i] == 2) {
                    a = i;
                }
                if (temp[i] == 0) {
                    b = i;
                }

            }
            return {a, b};
        }
    };

    int main() {
        Solution s;
        {
        std::vector<std::vector<int>> a {{1, 3},{2, 2}};
        std::vector<int> b {2, 4};
        assert(b == s.findMissingAndRepeatedValues(a));
        }
        {
        std::vector<std::vector<int>> a {{9, 1, 7},{8, 9, 2}, {3, 4, 6}};
        std::vector<int> b {9, 5};
        assert(b == s.findMissingAndRepeatedValues(a));
        }
    }