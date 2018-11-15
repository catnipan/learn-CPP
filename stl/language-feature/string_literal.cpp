#include <iostream>
using namespace std;

int main() {
  // use delimiter
  // start with foo(, and ends with )foo
  // thus we can write )" in the middle
  cout << R"foo(Hello )" World)foo" << endl;
  return 0;
}
