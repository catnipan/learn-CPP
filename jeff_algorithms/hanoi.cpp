#include <iostream>
#include <stack>

enum Tower { A, B, C };

using namespace std;

void hanoi(int n, Tower src, Tower dst, Tower tmp) {
  if (n > 0) {
    hanoi(n - 1, src, tmp, dst);
    cout << "move dist " << n << " from #" << src << " to #" << dst << "." << endl;
    hanoi(n - 1, tmp, dst, src);
  }
}

class HanoiNode {
private:
  int n;
  Tower src;
  Tower dst;
  Tower tmp;
public:
  HanoiNode(int no, Tower source, Tower destination, Tower temporary)
    : n(no), src(source), dst(destination), tmp(temporary) {
      // cout << "init hanoiNode" << endl;
    }
  // ~HanoiNode() {
  //   cout << "release hanoiNode" << endl;
  // }
  void move() {
    cout << "move disk " << n << " from #" << src << " to #" << dst << "." << endl;
  }
  HanoiNode* goUp() {
    if (n > 1) {
      return new HanoiNode{n - 1, src, tmp, dst};
    }
    return nullptr;
  }
  HanoiNode* goDown() {
    if (n > 1) {
      return new HanoiNode{n - 1, tmp, dst, src};
    }
    return nullptr;
  }
};

// hanoi algorithm of iterative style
void hanoiI(int n, Tower src, Tower dst, Tower tmp) {
  stack<HanoiNode*> s;
  HanoiNode* curr = new HanoiNode{n, src, dst, tmp};
  while (true) {
    // go to top and record node
    while (curr) {
      s.push(curr);
      curr = curr->goUp();
    }
    if (s.empty()) {
      break;
    }
    HanoiNode* hn = s.top();
    hn->move();

    s.pop();
    delete hn;

    curr = hn->goDown();
  }
}

int main() {
  // hanoi(3, A, B, C);
  // cout << "-----" << endl;
  hanoiI(10, A, B, C);
  // HanoiNode* curr = new HanoiNode{3, A, B, C};
  // stack<HanoiNode*> s;
  // HanoiNode* curr1 = curr->goUp();
  // s.push(curr1);
  // HanoiNode* curr2 = curr1->goDown();
  // s.push(curr2);
  // curr->move();
  // curr2->move();
  // s.top()->move();
}