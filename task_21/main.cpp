#include <algorithm>
#include <cassert>
#include <string>
#include <vector>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        auto pos = haystack.find(needle);
        if (pos == std::string::npos) return -1;
        return pos;
    }
};

  int main() {
      Solution s;
      // s
    //   {
    //   TreeNode pl(2);
    //   TreeNode qr(3);
    //   TreeNode p(1, &pl, &qr);
    //   TreeNode q(1, &qr, &pl);
    //       assert(false == s.isSameTree(&p, &q));
    //   }



  }