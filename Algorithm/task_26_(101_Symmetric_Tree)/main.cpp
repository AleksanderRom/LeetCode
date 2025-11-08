s#include <cassert>
// #include <deque>
// #include <map>
#include <string>
#include <vector>
// #include <unordered_set>
// #include <unordered_map>

//   Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

  class Solution {
     public:
      bool isSymmetric(TreeNode *p) {

        return RecurseFunction(p->left, p->right);
      }


     private:
      bool RecurseFunction(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr && q != nullptr) return false;
        if (p != nullptr && q == nullptr) return false;
        if (p->val != q->val) return false;
        if (!RecurseFunction(p->left, q->right)) {
            return false;
        }
        if (!RecurseFunction(p->right, q->left)) {
            return false;
        }
        return true;
      }
  };

  int main() {
      Solution s;
      // s
      {
      TreeNode pl(2);
      TreeNode qr(3);
      TreeNode p(1, &pl, &qr);
      TreeNode q(1, &qr, &pl);
          assert(false == s.isSameTree(&p, &q));
      }
      {
      TreeNode pl(2);
      TreeNode qr(3);
      TreeNode p(1, &pl, &qr);
      TreeNode q(1, &pl, &qr);
          assert(true == s.isSameTree(&p, &q));
      }


  }