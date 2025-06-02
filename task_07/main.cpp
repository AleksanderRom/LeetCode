#include <cassert>
#include <iostream>
#include <string>
#include <vector>

static char ReversS(char x) {
    if (x == '(') return ')';
    if (x == '[') return ']';
    if (x == '{') return '}';
    return {' '};
}

static bool Chek(char x) {
    if (x == '(' || x == '{' || x == '[') return true;
    return false;
}

class Solution {
   public:
    bool isValid(std::string s) {
        if (s.size() % 2 != 0) return false;
        std::vector<char> buffer;
        for (char x : s) {
            if (Chek(x)) {
                buffer.push_back(ReversS(x));
            }else if (buffer.empty() || x != buffer.back()) {
                return false;
            }else {
                buffer.pop_back();
            }
        }
        if (buffer.size() != 0)return false;        
        return true;
    }
};

int main() {
    Solution q;
    assert(false == q.isValid("){"));
    assert(false == q.isValid("(("));
    assert(true == q.isValid("(){}[]"));
    assert(false == q.isValid("(]"));
    assert(true == q.isValid("([])"));
}