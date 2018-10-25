#include <iostream>
#include <vector>
#include "./util/list_node.cpp"

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* _dummyHead = new ListNode(0);
      ListNode* pr = _dummyHead;
      int carryNum = 0;
      while (true) {
        bool isl1Valid = l1 != NULL;
        bool isl2Valid = l2 != NULL;
        if (!isl1Valid && !isl2Valid) {
          break;
        }
        int result = (isl1Valid ? l1->val : 0) + (isl2Valid ? l2->val : 0) + carryNum;
        if (result >= 10) {
          carryNum = 1;
          result -= 10;
        } else {
          carryNum = 0;
        }
        pr = pr->next = new ListNode(result);
        l1 = isl1Valid ? l1->next : l1;
        l2 = isl2Valid ? l2->next : l2;
      }
      if (carryNum == 1) {
        pr->next = new ListNode(1);
      }
      return _dummyHead->next;
    }
};

int main() {
  auto ln1 = fromList({2,4,3});
  auto ln2 = fromList({5,6,9});
  auto s = Solution();
  print(ln1);
  print(ln2);
  print(s.addTwoNumbers(ln1, ln2));
}