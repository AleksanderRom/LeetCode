#include <cassert>
#include <algorithm>
#include <vector>
//   Definition for singly-linked list.

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        massvect_.reserve(101);
        // list1.
         RecursTwo(list1, list2);
        //   result.val = massvect_[0]->val;
        //   result.next = massvect_[1];

         RecursOne(0, result);
         list1 = &result;
        return list1;
    }

        void RecursOne(size_t it, ListNode& Node) {

            // if (it == massvect_.size()-2) {;
            if (it == massvect_.size()-1) {;
                return; 
            }
              Node.val = massvect_[it]->val;
              Node.next = massvect_[it + 1];
            RecursOne(++it, *Node.next);
           return; 

        }


     void RecursTwo(ListNode* list1, ListNode* list2) {
        massvect_.push_back(list1);
        massvect_.push_back(list2);

        if (list1->next == nullptr && list2->next == nullptr) {
            std::sort(massvect_.begin(), massvect_.end(),[](ListNode* rvl, ListNode* lvl){return rvl->val < lvl->val; });
             return;

        }
           RecursTwo(list1->next, list2->next);
          return;

     }       
    
private:
 std::vector<ListNode*> massvect_;
 ListNode result;
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
    auto xx = x.mergeTwoLists(&y, &z);
    int i = 0;
}



// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         // ListNode* result;
//         massvect_.reserve(101);
//          RecursTwo(list1, list2);
//         result = RecursOne(massvect_.size());
//         // result = buf;
//         return &result;
//     }

//         ListNode RecursOne(int x) {
//             if (0 == x) {

//                 return ListNode (massvect_.back());
//             }
//             --x;

//            ListNode buf = RecursOne(x);
//            massvect_.pop_back();
//            return ListNode (massvect_.back(), &buf);

//         }


//      void RecursTwo(ListNode* list1, ListNode* list2) {
//         massvect_.push_back(list1->val);
//         massvect_.push_back(list2->val);

//         if (list1->next == nullptr && list2->next == nullptr) {
//             std::sort(massvect_.begin(), massvect_.end());
//              return;

//         }

//            RecursTwo(list1->next, list2->next);
//           return;

//      }  



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         massvect_.reserve(101);
//          RecursTwo(list1, list2);

//         result.val = massvect_[0].val;
//         result.next = &massvect_[1];
//          RecursOne(massvect_.size(), *result.next);
//         return &result;
//     }

//         void RecursOne(int x, ListNode& Node) {
//             if (2 == x) {;
//                 return; 
//             }
//             Node.val = massvect_[massvect_.size() - x + 1].val;
//             Node.next = &massvect_[massvect_.size() - x + 2];
//             --x;
//             RecursOne(x, *Node.next);
//            return; 

//         }


//      void RecursTwo(ListNode* list1, ListNode* list2) {
//         massvect_.push_back(list1->val);
//         massvect_.push_back(list2->val);

//         if (list1->next == nullptr && list2->next == nullptr) {
//             std::sort(massvect_.begin(), massvect_.end(),[](ListNode rvl, ListNode lvl){return rvl.val < lvl.val; });
//              return;

//         }
//            RecursTwo(list1->next, list2->next);
//           return;

//      }       
    
// private:
//  std::vector<ListNode> massvect_;
//  ListNode result;
// };