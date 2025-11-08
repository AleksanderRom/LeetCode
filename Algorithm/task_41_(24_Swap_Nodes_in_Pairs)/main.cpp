#include <cassert>

//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}

    //   bool operator=(const ListNode& rhs) {
          
        //   return true;
        // }
 };


 
class Solution {
public:
    ListNode* SwapRecurs (ListNode* ls, ListNode* rs) {
        // ListNode buf;
        // if (rs == nullptr) {
         //   return rs;
        // }
        ls->next = rs->next;
        rs->next = ls;
        if (ls->next == nullptr || ls->next->next == nullptr) {
            return rs;
        }
        // auto qq = SwapRecurs(ls->next, ls->next->next);
        // buf.next= 
         rs->next->next = SwapRecurs(ls->next, ls->next->next);
        return rs;
    }
    ListNode* swapPairs(ListNode* head) {
        if (head->next == nullptr) return head;
        auto qq = SwapRecurs(head, head->next);
        // int i = 0;
        return SwapRecurs(head, head->next);
    }
};


int main() {
    Solution s;
    using ln = ListNode;
    // ln r{ ln (1, new ln(2, new ln(3, new ln(4))))};
    // s.swapPairs(&r);
    // ln r2{ ln (1, new ln(2, new ln(3)))};
    ln r3{ ln (1, new ln(2))};
    // ln r3{};
    s.swapPairs(&r3);
    // ln r{ln(2, &ln(1, &ln{3}))};
    // assert((s.swapPairs(&r)->val == ln(2, new ln(1, new ln{3})).val));

}