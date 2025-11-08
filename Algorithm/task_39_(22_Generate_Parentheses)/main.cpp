#include <cassert>
#include <string>
#include <vector>

class Solution {
 static int CheckNumber(int n) {
    switch (n) {
        case 1: return 1;
        case 2: return 2;
        case 3: return 5;
        case 4: return 14;
        case 5: return 42;
        case 6: return 132;
        case 7: return 429;
        case 8: return 1430;
    }
    return 0;
}

void Recurs(int start, int end, int n, std::string str, std::vector<std::string>& buf) {
    if (str.size() == n * 2) {
        buf.push_back(str);
        return;
    }
    if (start < n) {
        Recurs(start + 1, end, n, str + '(', buf);
    }
    if (end < start) {
        Recurs(start, end + 1, n, str + ')', buf);
    }

}


   public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> buf;
        buf.reserve(CheckNumber(n));
        Recurs(0, 0, n, "", buf);
        return buf;
    }
};

int main() {
    Solution s;
    s.generateParenthesis(3);
}