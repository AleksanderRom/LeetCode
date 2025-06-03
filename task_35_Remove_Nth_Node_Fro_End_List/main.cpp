#include <cassert>
#include <vector>
//   Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n == 0) return head;
        std::vector<ListNode*> buf;
        buf.reserve(30);
        buf.push_back(head);
        ListNode temp = *head;
        while (temp.next != nullptr) {
            buf.push_back(temp.next);
            temp = *temp.next;
        }
        // ListNode* node_del = buf[buf.size() - n - 1];
        // ListNode* node_nex = buf[buf.size() - n]->next;
        // node_del->next = node_nex;
        int size = buf.size();
        if (size == 1) return {};
        if (size == n) {
            return head->next;
            //    int i = 99;
        }
        buf[size - n - 1]->next = buf[size - n]->next;

        // int i = 0;

        return head;
    }
};

int main() {
    Solution s;
    {
        ListNode l1 = 1, l2 = 2;
        l1.next = &l2;
        s.removeNthFromEnd(&l1, 2);
    }
    {
        ListNode l1 = 1, l2 = 2;
        l1.next = &l2;
        s.removeNthFromEnd(&l1, 1);
    }
    {
        ListNode l1 = 1, l2 = 2, l3 = 3, l4 = 4, l5 = 5;
        l4.next = &l5;
        l3.next = &l4;
        l2.next = &l3;
        l1.next = &l2;
        s.removeNthFromEnd(&l1, 2);
    }
    {
        ListNode l1 = 1;
        auto dd = s.removeNthFromEnd(&l1, 1);
        int i = 0;
    }
}