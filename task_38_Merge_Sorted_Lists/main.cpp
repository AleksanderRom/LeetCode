#include <vector>
#include <map>
#include <cassert>

//   Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        std::map<int, std::vector<ListNode*>> buffer;
        for (auto list : lists) {
            ListNode* temp = list;
            while (temp != nullptr) {
                buffer[temp->val].push_back(temp);
                temp = temp->next;
            }
        }
        //связывание
        ListNode* result = nullptr;
        for (auto it = buffer.rbegin(); it != buffer.rend(); ++it) {
            for (auto ls = it->second.rbegin(); ls != it->second.rend(); ++ls) {
                (*ls)->next = result;
                result = *ls;
            }
        }
        return result;
    }
};

int main () {
Solution s;
{
    ListNode jj;
    std::vector<ListNode*> list;
    list.push_back(&jj);
    auto vv = s.mergeKLists(list);
}
ListNode n1(1);
ListNode n2(4);
ListNode n3(5);
n2.next = &n3;
n1.next = &n2;

ListNode b1(1);
ListNode b2(3);
ListNode b3(4);
b2.next = &b3;
b1.next = &b2;

ListNode m1(2);
ListNode m2(6);
m1.next = &m2;

std::vector<ListNode*> list;
list.push_back(&n1);
list.push_back(&b1);
list.push_back(&m1);
auto vv = s.mergeKLists(list);
int i = 0;
}