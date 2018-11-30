#include "../stack.h"
#include <iostream>
using namespace std;

void trim(const char exp[], int& lo, int& hi) {
  while(lo <= hi) {
    if (exp[lo] == '(' || exp[lo] == ')') {
      break;
    }
    lo++;
  }
  while (lo <= hi) {
    if (exp[hi] == '(' || exp[hi] == ')') {
      break;
    }
    hi--;
  }
}

int divide(const char exp[], int lo, int hi) {
  int mi = lo;
  int crc = 1;
  while ((0 < crc) && (++mi < hi)) {
    switch (exp[mi]) {
      case '(':
        crc++;
        break;
      case ')':
        crc--;
        break;
    }
  }
  return mi;
}

bool parenR(const char exp[], int lo, int hi) {
  trim(exp, lo, hi);
  if (lo > hi) {
    // means containing no parenthese
    return true;
  }
  if (exp[lo] != '(') {
    return false;
  }
  if (exp[hi] != ')') {
    return false;
  }
  int mi = divide(exp, lo, hi);
  return parenR(exp, lo + 1, mi - 1) && parenR(exp, mi + 1, hi);
}

bool parenI(const char exp[], int lo, int hi) {
  Stack<char> paren_stack;
  for (int i = lo; i <= hi; i++) {
    switch (exp[i]) {
      case '(':
      case '[':
      case '{':
        paren_stack.push(exp[i]);
        break;
      case ')':
        if (paren_stack.empty() || ('(' != paren_stack.pop())) {
          return false;
        }
        break;
      case ']':
        if (paren_stack.empty() || ('[' != paren_stack.pop())) {
          return false;
        }
        break;
      case '}':
        if (paren_stack.empty() || ('{' != paren_stack.pop())) {
          return false;
        }
        break;
      default:
        break;
    }
  }
  return paren_stack.empty();
}

int main() {
  const char str[] = "123+434+(334+(45/32+3)+32+(32-223*(344-32)))+34";
  int lo = 0;
  int hi = 47;
  cout << "paren match?" << (parenI(str, lo, hi) ? "yes" : "no") << endl;
}