#include <cassert>
#include <string>
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std::literals;

class Solution {
   public:
    int longestValidParentheses(std::string s) {
        std::stack<int> stack;
        stack.push(-1);
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stack.push(i);
            } else {
                if (stack.size() == 1) {
                    stack.top() = i;
                } else {
                    stack.pop();
                    result = std::max(result, (i - stack.top()));
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    // {
    //     std::string str = ")("s;
    //     assert(0 == s.longestValidParentheses(str));
    // }
    {
        std::string str = "()())()()()"s;
        assert(6 == s.longestValidParentheses(str));
    }
    {
        std::string str = "()(()())"s;
        assert(8 == s.longestValidParentheses(str));
    }
    {
        std::string str = "()(()()"s;
        assert(4 == s.longestValidParentheses(str));
    }
    {
        std::string str = "()(()(()()()"s;
        assert(6 == s.longestValidParentheses(str));
    }
    {
        std::string str = "()(()"s;
        assert(2 == s.longestValidParentheses(str));
    }
    {
        std::string str = ")()())"s;
        assert(4 == s.longestValidParentheses(str));
    }
    {
        std::string str = "(()"s;
        assert(2 == s.longestValidParentheses(str));
    }
}

//     if (s.size() < 2) return 0;
//     auto it = s.begin();
//     int result;
//     int open_count;
//     int buffer_count;
//     result = open_count = buffer_count = 0;
//     while (it != s.end()) {
//         if (*it == '(') {
//             ++open_count;
//         } else if (open_count > 0) {
//             ++buffer_count;
//             --open_count;
//         } else {
//             result = std::max(result, buffer_count);
//             open_count  = 0;
//             // open_count = closed_count = 0;
//         }

//         ++it;
//     }
//     // if (open_count != closed_count) {
//     //     return std::max(result, (open_count - closed_count) * 2);
//     // }
//     return std::max(result, buffer_count);
// }