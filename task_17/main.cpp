#include <cassert>
#include <vector>

class Solution {
   public:
    int searchInsert(std::vector<int>& v, int num) {
        auto top = v.end();
        auto low = v.begin();
        size_t size = v.size();
        while (size != 0) {
            size = (top - low) / 2;
            if (*(low + size) == num) {
                return (low + size) - v.begin();
            } else if (*(low + size) > num) {
                if (size == 0) return low - v.begin();
                top -= size;
            } else {
                if (size == 0) break;
                low += size;
            }
        }
        return top - v.begin();
    }
};

int main() {
    Solution s;
        {
        //                  0  1  2  3  4  5  6
        std::vector<int> v1{1, 3, 5, 6};
        assert(s.searchInsert(v1, 5) == 2);
    }

    {
        //                  0  1  2  3  4  5  6
        std::vector<int> v1{1, 3, 5, 6, 7, 8, 9};
        assert(s.searchInsert(v1, 4) == 2);
    }
    {
        //                  0  1  2  3
        std::vector<int> v1{1, 3, 5};
        assert(s.searchInsert(v1, 6) == 3);
    }
    {
        std::vector<int> v1(1001, 0);
        for (int i = 0; i < v1.size(); ++i) {
            v1[i] = i + 2;
        }
        assert(s.searchInsert(v1, 1) == 0);
    }
    {
        //                  0  1  2  3
        std::vector<int> v1{2, 3, 5, 6};
        assert(s.searchInsert(v1, 1) == 0);
    }
    {
        //                  0  1  2  3
        std::vector<int> v1{5};
        assert(s.searchInsert(v1, 1) == 0);
    }
    {
        //                  0  1  2  3
        std::vector<int> v1{1};
        assert(s.searchInsert(v1, 5) == 1);
    }
    {
        //                  0  1  2  3
        std::vector<int> v1{1, 3, 5, 6};
        assert(s.searchInsert(v1, 5) == 2);
    }
    {
        //                  0  1  2  3
        std::vector<int> v1{1, 3, 5, 6};
        assert(s.searchInsert(v1, 2) == 1);
    }
    {
        //                  0  1  2  3
        std::vector<int> v1{1, 3, 5, 6};
        assert(s.searchInsert(v1, 7) == 4);
    }

    {
        std::vector<int> v1{1, 3, 4, 5, 6, 7, 8, 9};
        assert(s.searchInsert(v1, 4) == 2);
    }
    {
        std::vector<int> v1(1001, 0);
        for (int i = 0; i < v1.size(); ++i) {
            v1[i] = i;
        }
        assert(s.searchInsert(v1, 688) == 688);
    }
}