#include <string>
#include "../stack.h"

using std::string;

string convert(int n, int base) {
  static char digit[] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
  };

  Stack<char> outputStack;

  while (n > 0) {
    outputStack.push(digit[n % base]);
    n = n / base;
  }

  string s;
  while (!outputStack.empty()) {
    s += outputStack.pop();
  }
  return s;
}