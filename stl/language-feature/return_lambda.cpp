#include <iostream>
#include <functional>

using namespace std;

function<int(int, int)> returnLambda() {
  return [](int x, int y) {
    return x * y;
  };
}

int main() {
  auto lf = returnLambda();
  cout << lf(3, 4) << endl;
}