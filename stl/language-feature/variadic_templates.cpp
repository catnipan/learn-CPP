#include <iostream>
#include <string>
#include <bitset>
using namespace std;

void print() {}

template <typename T, typename... Types>
void print(const T& firstArg, const Types&... args) {
  cout << firstArg << endl;
  print(args...);
}

int main() {
  print(8, 3.2, "hello", bitset<16>(377), 42);
}