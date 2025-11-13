#include <algorithm>
#include <cassert>
#include <numeric>
#include <stack>
#include <string>
#include <vector>
// #include <pair>

using namespace std;

class BlackBrick {
   public:
    explicit BlackBrick(int count)
        : black_brick_(count) {}

    void Clear() {
        for (auto i = 0; i < max_count; ++i) {
            black_brick_[i] = 0;
        }
        max_count = 0;
    }

    int GetNum(int i) {
        if (i == 0) return 0;
        // return black_brick_[i-1];
        return std::accumulate(black_brick_.begin(), black_brick_.begin() + i, 0);
    }

    void AddBrick(int n) {
        for (auto i = 0; i < n; ++i) {
            ++black_brick_[i];
        }
        // for(auto i = 0; i < n; ++i) {
        //     int prev = (i != 0) ? black_brick_[i -1] : 0;
        //     black_brick_[i] += prev + 1;

        // }
        max_count = max(max_count, n);
    }

    pair<vector<int>, int> GetBlackBrick() {
        return {black_brick_, max_count};
    }

   private:
    vector<int> black_brick_;
    int max_count = 0;
};

class Solution {
    struct info {
        int pos = 0;
        int h = 0;
        int prev_water = 0;
    };

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
        int max_br = MaxHeight(height);
        BlackBrick black_brick(max_br);
        stack<info> stack;

        for (auto i = 0; i < height.size(); ++i) {
            int cur_h = height[i];
            if (cur_h == 0) continue;

            if (stack.empty()) {               // первая встреча башни
                stack.push({i, cur_h, 0});  //, BlackBrick{max_br}});
            } else {
                auto st = stack.top();

                while (stack.size() > 1) {
                    if (cur_h <= st.h) break;
                    stack.pop();
                    st = stack.top();
                }

                if (cur_h < st.h) {
                    water = st.prev_water + ((i - st.pos - 1) * cur_h) - black_brick.GetNum(cur_h);
                    stack.push({i, cur_h, water});
                    black_brick.AddBrick(cur_h);
                } else {
                    if (!stack.empty()) stack.pop();
                    water = st.prev_water + ((i - st.pos - 1) * st.h) - black_brick.GetNum(st.h);

                    stack.push({i, cur_h, water});
                    black_brick.Clear();
                }
            }

            // black_brick.AddBrick(cur_h);
        }
        return stack.top().prev_water;
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
        assert(17 == s.trap({4, 0, 2, 1, 2, 0, 4}));
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
        BlackBrick bl(9);
        bl.AddBrick(3);
        bl.AddBrick(1);
        bl.AddBrick(8);
        auto dd = bl.GetNum(1);
        assert(3 == bl.GetNum(1));
        assert(7 == bl.GetNum(3));
        assert(8 == bl.GetNum(4));
        assert(12 == bl.GetNum(8));
        assert(12 == bl.GetNum(9));
        bl.Clear();
        // auto i = 0;
    }

    // {
    //     Solution s;
    //     auto temp = s.trap({6, 4, 2, 0, 3, 2, 0, 3, 1, 4, 5, 3, 2, 7, 5, 3, 0, 1, 2, 1, 3, 4, 6, 8, 1, 3});
    //     assert(83 == s.trap({6, 4, 2, 0, 3, 2, 0, 3, 1, 4, 5, 3, 2, 7, 5, 3, 0, 1, 2, 1, 3, 4, 6, 8, 1, 3}));
    // }
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
