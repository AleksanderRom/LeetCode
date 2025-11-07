#include <cassert>
#include <algorithm>

//   Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0), next(nullptr) {}
    ListNode(int x)
        : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next)
        : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int i = 0;
        int temp = 0;
        auto buf1 = l1;
        auto buf2 = l2;
        while (true) {
            temp = i + buf1->val + buf2->val;
            i = 0;
            if (temp >= 10)  {
                temp -= 10;
                i = 1;
            }
            buf1->val = temp;
            if (buf1->next != nullptr && buf2->next != nullptr) {
                buf1 = buf1->next;
                buf2 = buf2->next;
                
            }
            else if (buf1->next != nullptr && buf2->next == nullptr) {
                if (i == 0) {
                    break;
                }
                buf1 = buf1->next;
                buf2->val = 0;
            }
            
            else if (buf1->next == nullptr && buf2->next != nullptr) {
                std::swap(buf1->next, buf2->next);
                buf1 = buf1->next;
                if (i == 0) {
                    break;
                }
                buf2->val = 0;
            }
            else if (buf1->next == nullptr && buf2->next == nullptr) {
                if (i == 0) {
                    break;
                }
                // else if (buf1->next == nullptr && buf2->next == nullptr && i == 1) {
                    buf1->next = l2;
                    buf1->next->next = nullptr;
                    buf1->next->val = i;
                    break;
                // }
            }

        }
    return l1;
    }
};

int main() {
    Solution s;
    // {
    // ListNode aaa(3);
    // ListNode aa(4, &aaa);
    // ListNode a (2, &aa);
    // ListNode bbb(4);
    // ListNode bb(6, &bbb);
    // ListNode b (5, &bb);
    // auto c = s.addTwoNumbers(&a, &b);
    // int i = 0;
    // }
    {
        ListNode a1(9);
        ListNode a2(9, &a1);
        ListNode a3(9, &a2);
        ListNode a4(9, &a3);
        ListNode a5(9, &a4);
        ListNode a6(9, &a5);
        ListNode a(9, &a6);
        // ListNode a (9, &a7);
        ListNode b1(9);
        ListNode b2(9, &b1);
        ListNode b3(9, &b2);
        ListNode b (9, &b3);
        auto c = s.addTwoNumbers(&a, &b);
        int i = 0;
    }
    {
        ListNode aaa(9);
        ListNode aa(4, &aaa);
        ListNode a (2, &aa);
        ListNode bbbb(9);
        ListNode bbb(4, &bbbb);
        ListNode bb(6, &bbb);
        ListNode b (5, &bb);
        auto c = s.addTwoNumbers(&a, &b);
        int i = 0;
        }
}