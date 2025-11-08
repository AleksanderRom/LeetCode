#include <algorithm>
#include <cassert>
// #include <string>
#include <cmath>
#include <numeric>
#include <vector>

// class Solution {
//     public:
//      long long maxWeight(std::vector<int>& pizzas) {

//          std::sort(pizzas.begin(), pizzas.end());
//          long long result = 0;
//          int n = pizzas.size();
//          int size = n / 4;  // кол-во дней
//          int size_n = (size + 1) / 2;  // кол-во дней нечетных
//         //  auto it = pizzas.rbegin();
//         int indx = n - 1;

//         //  for (int i = 0; i <size_n; ++i) {
//         //      result += pizzas[indx];
//         //      --indx;
//         //  }
//         //  for (int i = 0; i <size / 2; ++i) {
//         //     --indx;
//         //      result += pizzas[indx];
//         //      --indx;

//         //  }
//          return result;
//      }
//  };

// class Solution {
//     public:
//      long long maxWeight(std::vector<int>& pizzas) {

//          std::sort(pizzas.begin(), pizzas.end());
//          long long result = 0;
//          int size = pizzas.size() / 4;  // кол-во дней
//          int size_n = (size + 1) / 2;  // кол-во дней нечетных
//          auto it = pizzas.rbegin();

//          for (int i = 0; i <size_n; ++i) {
//              result += *it;
//              ++it;
//          }
//          for (int i = 0; i <size / 2; ++i) {
//              ++it;
//              result += *it;
//              ++it;

//          }
//          return result;
//      }
//  };

class Solution {
   public:
    long long maxWeight(std::vector<int>& pizzas) {
        std::sort(pizzas.begin(), pizzas.end());
        long long result = 0;
        int size = pizzas.size();    // размер вектора
        int day = size / 4;          // кол-во дней
        int size_n = (day + 1) / 2;  // кол-во дней нечетных
        auto it = pizzas.rbegin();
        // auto it2 = pizzas.rbegin() + size_n;
        if (day == 1) {
            return pizzas[3];
        }

        if (size % 2 == 0) {
            result = std::accumulate(it, it + size_n, 0);
            ++it;
            // for (it = (it + size_n); it2 < it + size_n + day / 2 + 1; it2 += 2) {
            for (auto it2 = (it + size_n); it2 < it + size_n + day / 2 + 1; it2 += 2) {
                result += *it2;
            }
            return result;
        }
        return result;
    }
};

int main() {
    Solution s;
    {
        std::vector<int> q{2, 5, 2, 3};
        assert(5 == s.maxWeight(q));
    }
    {
        std::vector<int> q{3, 4, 2, 4, 2, 4, 2, 2, 4, 5, 3, 2, 1, 2, 1, 1};
        assert(16 == s.maxWeight(q));
    }
    {
        std::vector<int> q{5, 3, 1, 1, 3, 3, 2, 1, 5, 4, 2, 1};
        assert(13 == s.maxWeight(q));
    }
    {
        std::vector<int> q{5, 2, 2, 4, 3, 3, 1, 3, 2, 5, 4, 2};
        assert(14 == s.maxWeight(q));
    }
    {
        std::vector<int> q{1, 5, 6, 3, 2, 6, 7, 8};
        assert(14 == s.maxWeight(q));
    }
    {
        std::vector<int> q{2, 1, 1, 1, 1, 1, 1, 1};
        assert(3 == s.maxWeight(q));
    }
}