  #include <algorithm>
#include <vector>
  
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1 || !list2)
      return list1 ? list1 : list2;
    if (list1->val > list2->val)
      std::swap(list1, list2);
    list1->next = mergeTwoLists(list1->next, list2);
    return list1;
  }
};


int main () {
    Solution x;
    // ListNode y1 (4);
    ListNode y1 (4);
    ListNode y2 (2, &y1);
    ListNode y (1, &y2);
    ListNode z1 (4);
    ListNode z2 (3, &z1);
    ListNode z (1, &z2);
    // ListNode z (1, &ListNode(2, &ListNode(4)));
// int i = 0;
    // ListNode y(1, ListNode(2), ListNode(3));
    // x(1);
    {
    auto xx = x.mergeTwoLists(&y, &z);
    int i = 0;
    }
    int i = 0;
}