#include <cassert>
#include <iostream>

//   Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

    //   bool operator=(const ListNode& rhs) {

    //   return true;
    // }
};

void Print(std::ostream& out, ListNode* ln) {
    while (ln != nullptr) {
        out << ln->val << " ";
        ln = ln->next;
    }
    out << std::endl;
}

class Solution {
   public:
    ListNode* SwapRecurs(ListNode* start, ListNode* current) {
        ListNode* subseq = current->next;
        current->next = current->next->next;  // pass one
        subseq->next = start;
        return subseq;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node_end = head;
        ListNode* node_link = head;
        ListNode* node_start = head;
        bool flag_first = true;
        while (true) {
            int count = k;
            ListNode* node = node_start;
            // cycle node check for nullptr value
            while (true) {
                if (nullptr == node) {
                    return head;
                }
                if (1 == count) break;
                node = node->next;
                --count;
            }
            // cycle swap
            int i = k;
            ListNode* buf = node_start;
            while (i > 1) {
                node_start = SwapRecurs(node_start, buf);
                --i;
            }
            if (flag_first) {
                head = node_start;
                flag_first = false;
            } else {
                 node_link->next = node;
                 node_link = buf;
            }
            node_start = buf->next;
        }
        return head;
    }
};

// bool operator==(ListNode& ln, ListNode& rn){
//     while(ln.next != nullptr )
//     return true;
// }

int main() {
    Solution s;
    using ln = ListNode;
    {
        ln r(0);
        int i = 1;
        std::cout << i << ": ";
        Print(std::cout, s.reverseKGroup(&r, i));
    }
    {
        ln r6(6);
        ln r5(5, &r6);
        ln r4(4, &r5);
        ln r3(3, &r4);
        ln r2(2, &r3);
        ln r1(1, &r2);
        int i = 1;
        std::cout << i << ": ";
        Print(std::cout, s.reverseKGroup(&r1, i));
    }
    {
        ln r6(6);
        ln r5(5, &r6);
        ln r4(4, &r5);
        ln r3(3, &r4);
        ln r2(2, &r3);
        ln r1(1, &r2);
        int i = 2;
        std::cout << i << ": ";
        Print(std::cout, s.reverseKGroup(&r1, i));
    }
    {
        ln r6(6);
        ln r5(5, &r6);
        ln r4(4, &r5);
        ln r3(3, &r4);
        ln r2(2, &r3);
        ln r1(1, &r2);
        int i = 3;
        std::cout << i << ": ";
        Print(std::cout, s.reverseKGroup(&r1, i));
    }
    {
        ln r6(6);
        ln r5(5, &r6);
        ln r4(4, &r5);
        ln r3(3, &r4);
        ln r2(2, &r3);
        ln r1(1, &r2);
        int i = 4;
        std::cout << i << ": ";
        Print(std::cout, s.reverseKGroup(&r1, i));
    }
    {
        ln r6(6);
        ln r5(5, &r6);
        ln r4(4, &r5);
        ln r3(3, &r4);
        ln r2(2, &r3);
        ln r1(1, &r2);
        int i = 5;
        std::cout << i << ": ";
        Print(std::cout, s.reverseKGroup(&r1, i));
    }
    // ln r{ln(1, new ln(2, new ln(3, new ln(4, new ln(5, new ln(6))))))};
    // auto q = s.reverseKGroup(&r, 3);
    // ln rm{ln(3, new ln(2, new ln(1, new ln(6, new ln(5, new ln(4))))))};
    // assert(&rm == &r);
    // }
    // {
    // ln r{ln(1, new ln(2, new ln(3, new ln(4, new ln(5, new ln(6))))))};
    // s.reverseKGroup(&r, 4);
    // }

    // {
    // ln r{ln(1, new ln(2, new ln(3, new ln(4, new ln(5)))))};
    // s.reverseKGroup(&r, 3);
    // Print(std::cout, s.reverseKGroup(&r, 3));
    // }
}