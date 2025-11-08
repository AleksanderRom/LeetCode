#include <vector>
#include <cassert>
// #include <iterator>

class Solution {
    public:
        std::vector<int> pivotArray(std::vector<int>& nums, int pivot) {
            std::vector<int> result;
            result.reserve(nums.size()); // Резервируем память для результата
    
            // Сначала добавляем элементы меньше pivot
            for (int num : nums) {
                if (num < pivot) {
                    result.push_back(std::move(num));
                }
            }
    
            // Затем добавляем элементы равные pivot
            for (int num : nums) {
                if (num == pivot) {
                    result.push_back(std::move(num));
                }
            }
    
            // Наконец, добавляем элементы больше pivot
            for (int num : nums) {
                if (num > pivot) {
                    result.push_back(std::move(num));
                }
            }
    
            return result;
        }
    };

// class Solution {
//     public:
//         std::vector<int> pivotArray(std::vector<int>& nums, int pivot) {
//             std::vector<int> result(nums.size());
//             auto left = result.begin();
//             auto centre = result.begin();
//             auto right = result.end();
            
//             for (int& num : nums) {
//                 if (num < pivot) {
//                     *left = num;
//                     left++;
//                 } else if (num > pivot) {
//                     right--;
//                     *right = num;
//                 }
//             }
            
//             // Заполнение pivot элементами
//             std::fill(left, right, pivot);
            
//             // Корректировка размера
//             result.resize(std::distance(result.begin(), right) + 1);
            
//             return result;
//         }
//     };

// class Solution {
//     public:
//         std::vector<int> pivotArray(std::vector<int>& nums, int pivot) {
//             std::vector<int> result(nums.size());
//             // std::vector<int> left;
//             auto left = result.begin();
//             // std::vector<int> right;
//             auto right = result.begin();
//             // std::vector<int> centre;
//             auto centre = result.begin();            
//             for (int& num : nums) {
//                 if (num < pivot) {
//                     *left = std::move(num);
//                     left++;
//                     right++;
//                     centre++;
//                 }else if (num > pivot) {
//                     right++;
//                     *right = std::move(num);
//                 }else {
//                     *centre = std::move(num);
//                     centre++;
//                     right++;
//                 }
//             }
//             // std::fill(left, centre, pivot);
//             // for (int& num : nums) {
//             //     if (num > pivot) {
//             //         *right = std::move(num);
//             //         right++;
//             //     }
//             // }
//             result.resize(std::distance(result.begin(), right));
//             // std::vector<int> result; //(left.begin(), left.end());
//             // result.reserve(nums.size());
//             // result.insert(result.begin(), left.begin(), left.end());
//             // result.insert(result.end(), centre.begin(), centre.end());
//             // result.insert(result.end(), right.begin(), right.end());
            
//             return result;
//         }
//     };
    //         std::vector<int> left;
    //         left.reserve(nums.size());
    //         std::vector<int> right;
    //         right.reserve(nums.size());
    //         std::vector<int> centre;
    //         centre.reserve(nums.size());            
    //         for (int& num : nums) {
    //             if (num < pivot) {
    //                 left.push_back(std::move(num));
    //             }else if (num > pivot) {
    //                 right.push_back(std::move(num));
    //             }else {
    //                 centre.push_back(std::move(num));
    //             }
    //         }
    //         std::vector<int> result; //(left.begin(), left.end());
    //         result.reserve(nums.size());
    //         result.insert(result.begin(), left.begin(), left.end());
    //         result.insert(result.end(), centre.begin(), centre.end());
    //         result.insert(result.end(), right.begin(), right.end());
            
    //         return result;
    //     }
    // };


int main() {
    Solution s;
    {
        std::vector<int> a {9, 12, 5, 10, 14, 3, 10};
        std::vector<int> b {9, 5, 3, 10, 10, 12, 14};
        assert(b == s.pivotArray(a, 10));
    }
    {
        std::vector<int> a {-3, 4, 3, 2};
        std::vector<int> b {-3, 4, 3, 2};
        assert(b == s.pivotArray(a, 10));
    }
}