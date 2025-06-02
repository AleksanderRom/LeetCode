#include <cassert>
#include <map>
#include <vector>

class Solution {
   public:
    int maxArea(std::vector<int>& h) {
        int result = 0, l = 0, r = h.size() - 1;
        while (l < r) {
            result = std::max(result, Sqr(std::min(h[l], h[r]), l, r));
            if (h[l] < h[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return result;
    }

    int Sqr(int level, int a, int b) {
        return level * (std::abs(a - b));
    }
};

int main() {
    Solution s;

    {
        std::vector<int> v{76, 155, 15, 188, 180, 154, 84, 34, 187, 142, 22, 5,
                           27, 183, 111, 128, 50, 58, 2, 112, 179, 2, 100, 111,
                           115, 76, 134, 120, 118, 103, 31, 146, 58, 198, 134,
                           38, 104, 170, 25, 92, 112, 199, 49, 140, 135, 160, 20,
                           185, 171, 23, 98, 150, 177, 198, 61, 92, 26, 147, 164,
                           144, 51, 196, 42, 109, 194, 177, 100, 99, 99, 125, 143,
                           12, 76, 192, 152, 11, 152, 124, 197, 123, 147, 95, 73,
                           124, 45, 86, 168, 24, 34, 133, 120, 85, 81, 163, 146,
                           75, 92, 198, 126, 191};
        assert(18048 == s.maxArea(v));
    }
    {
        std::vector<int> v{8, 20, 1, 2, 3, 4, 5, 6};
        assert(42 == s.maxArea(v));
    }
    {
        std::vector<int> v{1, 8, 6, 2, 5, 4, 8, 3, 7};
        assert(49 == s.maxArea(v));
    }
    {
        std::vector<int> v{1, 2, 4, 3};
        assert(4 == s.maxArea(v));
    }
    {
        std::vector<int> v{1, 1};
        assert(1 == s.maxArea(v));
    }
    {
        std::vector<int> v{0, 0};
        assert(0 == s.maxArea(v));
    }
}

// class Solution {
//    public:
//     int maxArea(std::vector<int>& height) {
//         std::pair<int, int> left_max{0, 0};
//         std::pair<int, int> right_max{0, 0};
//         int n = height.size();
//         std::map<int, std::vector<int>> buffer;
//         for (int i = 0; i < n; ++i) {
//             buffer[height[i]].push_back(i);
//         }

//         if ((buffer.rbegin())->second.size() > 1) {
//             auto buf = buffer.rbegin();
//             left_max.first = right_max.first = buf->first;
//             left_max.second = *(buf->second.begin());
//             right_max.second = *(buf->second.rbegin());
//         } else {
//             auto one = std::next(buffer.begin(), buffer.size() - 1);
//             auto two = std::next(buffer.begin(), buffer.size() - 2);
//             if (one->second > two->second) {
//                 left_max.second = two->second[0];
//                 right_max.second = one->second[one->second.size() - 1];
//             } else {
//                 left_max.second = one->second[0];
//                 right_max.second = two->second[two->second.size() - 1];
//             }
//             left_max.first = right_max.first = std::min(one->first, two->first);
//         }
//         // крайние позиции
//         // корректировка
//         int level = left_max.first;

//         std::pair<int, int> temp_max_r = right_max;
//         int result = Sqr(left_max.first, left_max.second, right_max.second);
//         for (int i = temp_max_r.second; i < n; ++i) {
//             int level_buf = std::min(left_max.first, height[i]);
//             int buf = Sqr(level_buf, left_max.second, i);
//             if (result < buf) {
//                 level = level_buf;
//                 result = buf;
//                 temp_max_r.second = i;
//             }
//         }
//         std::pair<int, int> temp_max_l = left_max;
//         temp_max_r.first = level;
//         level = left_max.first;
//         // left_max.first = right_max.first = level;
//         for (int i = temp_max_l.second; i >= 0; --i) {
//             int level_buf = std::min(right_max.first, height[i]);
//             int buf = Sqr(level_buf, i, right_max.second);
//             if (result < buf) {
//                 level = level_buf;
//                 result = buf;
//                 temp_max_l.second = i;
//             }
//         }
//         // }
//         // вычисляем площадь
//         temp_max_l.first = level;
//         result = Sqr(std::min(temp_max_l.first, temp_max_r.first), temp_max_l.second, temp_max_r.second);
//         return result;
//     }

//     int Sqr(int level, int a, int b) {
//         return level * (std::abs(a - b));
//     }
// };