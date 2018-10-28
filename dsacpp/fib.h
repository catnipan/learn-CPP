#pragma once

class Fib {
private:
  int cur, nxt;
public:
  Fib (int n) {
    // first fibonacci number not less than n
    cur = 0;
    nxt = 1;
    while (cur < n) {
      next();
    }
  }
  int get() {
    return cur;
  }
  int next() {
    int oldCur = cur;
    cur = nxt;
    nxt = oldCur + nxt;
    return cur;
  }
  int prev() {
    int oldNxt = nxt;
    nxt = cur;
    cur = oldNxt - cur;
    return cur;
  }
};
