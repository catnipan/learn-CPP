#include <iostream>
#include <vector>
#include "./list_node.h"

using namespace std;

void print(ListNode* node) {
  while (true) {
    if (node == NULL) {
      break;
    }
    cout << node->val;
    node = node->next;
    if (node != NULL) {
       cout << "->";
    }
  }
  cout << endl;
}

ListNode* fromList(vector<int> xs){
  auto _dummyHead = new ListNode(0);
  auto prn = _dummyHead;
  for (auto p = xs.begin(); p != xs.end(); p++) {
    auto nxtNode = new ListNode(*p);
    prn = prn->next = nxtNode;
  }
  return _dummyHead->next;
};