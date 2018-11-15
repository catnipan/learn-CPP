#include <iostream>
#include <string>
using namespace std;

int main() {
  // define lambda function and call immediately
  [] {
    cout << "hello lambda" << endl;
  } ();

  // with no parameter
  auto l1 = [] {
    cout << "hello lambda2" << endl;
  };
  l1();

  auto l2 = [] (const string& s) {
    cout << s << endl;
  };
  l2("hello lambda3");

  auto l3 = [] () -> double {
    return 42;
  };
  cout << l3() << endl;

  int x = 0;
  int y = 42;
  auto qqq = [x,&y] {
    cout << "inside qqq: x:" << x << "\ty:" << y << endl;
    ++y;
    // error: cannot assign to a variable captured by copy in a non-mutable lambda
    // ++x;
  };
  qqq();
  cout << "after call qqq, y:" << y << endl;
  x = y = 22;
  qqq();
  cout << "outside: x:" << x << "\ty:" << y << endl;

  int id = 0;
  auto f = [id] () mutable {
    cout << "id: " << id << endl;
    id++;
  };
  f();
  f();
  f();
}