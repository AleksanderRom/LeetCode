#include <cassert>

class Solution {
    public:
        long long coloredCells(int n) {
            long long temp = 0;
            for(int i = 1; i <= n; ++i) {
                 temp + (i - 1);
            }
        return (1 + 4 * temp);
        }
    };

int main() {
    Solution s;
    {assert(1 == s.coloredCells(1));}
    {assert(5 == s.coloredCells(2));}
    {assert(13 == s.coloredCells(3));}
    {assert(25 == s.coloredCells(4));}
    // {int i = s.coloredCells(3);}
    // {int i = s.coloredCells(4);}
    // {int i = s.coloredCells(5);}
    // {int i = s.coloredCells(6);}
    // {int i = s.coloredCells(7);}


}