#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    string countAndSay(int n) {
        std::vector<int> prev({1});
        std::vector<int> cur({1});
        for (auto i = 1; i < n; ++i) {
            cur = CountDublicat(prev);
            std::swap(cur, prev);
        }

        return VectorToString(std::move(prev));
    }

    std::string VectorToString(std::vector<int> v) {
        std::string result;
        for (auto num : v) {
            result.push_back(num + 48);
        }
        return result;
    }

    std::vector<int> CountDublicat(const std::vector<int>& v) {
        std::vector<int> result;
        int count = 0;
        int prev = v[0];
        for (int num : v) {
            if (prev == num) {
                ++count;
            } else {
                count = count == 0 ? 1 : count;
                result.push_back(count);
                result.push_back(prev);
                count = 1;
                prev = num;
            }

        }
        result.push_back(count);
        result.push_back(prev);
        return result;
    }

};

void Test();
int main() {
    Test();
}

void Test() {
    Solution s;
    string ss;
    assert((vector<int>{1,1} == s.CountDublicat({1})));
    assert((vector<int>{2,1} == s.CountDublicat({1,1})));
    assert((vector<int>{1,1,1,2,2,1} == s.CountDublicat({1,2,1,1})));
    assert((vector<int>{3,1,1,2} == s.CountDublicat({1,1,1,2})));
    assert((vector<int>{1,2,1,1} == s.CountDublicat({2,1})));
    assert((vector<int>{1,1,1,2,2,1} == s.CountDublicat({1,2,1,1})));
    assert((vector<int>{4,1} == s.CountDublicat({1,1,1,1})));
    ss = s.countAndSay(1);
    assert("1" == s.countAndSay(1));
    ss = s.countAndSay(2);
    assert("11" == s.countAndSay(2));
    ss = s.countAndSay(3);
    assert("21" == s.countAndSay(3));
    ss = s.countAndSay(4);
    assert("1211" == s.countAndSay(4));
    ss = s.countAndSay(5);
    assert("111221" == s.countAndSay(5));
    ss = s.countAndSay(6);
    assert("312211" == s.countAndSay(6));
    ss = s.countAndSay(7);
    assert("13112221" == s.countAndSay(7));
    ss = s.countAndSay(8);
    assert("1113213211" == s.countAndSay(8));
    ss = s.countAndSay(8);
    assert("1113213211" == s.countAndSay(8));
    // cout << s.countAndSay(1) << endl;
}
