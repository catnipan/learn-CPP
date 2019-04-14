#include <utility>
#include <iostream>
#include <tuple>
#include <functional>

struct Test {
  int i, j;
};

class Foo {
  int data;
public:
  Foo (std::tuple<int, float>) {
    std::cout << "Foo:Foo(tuple)" << std::endl;
  }
  template <typename... Args>
  Foo (Args... args) {
    std::cout << "Foo::Foo(args...)" << std::endl;
  }
  // Foo(int a, float b) {
  //   std::cout << "Foo::Foo(int a, float b)" << std::endl;
  //   data = a + b;
  // }
};


int main() {
  int i = 3;
  std::pair<int, int> p(std::move(i), 3);

  std::cout << p.first << std::endl;
  // std::cout << i << std::endl;

  Test t{1, 2};
  std::pair<Test, int> p1(std::move(t), 4);
  // std::cout << t.i << std::endl;
  std::cout << p1.first.i << std::endl;
  std::cout << p1.first.j << std::endl;

  std::tuple<int, float> tt(1, 2.22);
  std::pair<int, Foo> p2(42, tt);
  std::pair<int, Foo> p3(std::piecewise_construct, std::make_tuple(42), tt);


  int j = 0;
  auto p4 = std::make_pair(std::ref(j), std::ref(j));
  ++p4.first;
  ++p4.second;
  std::cout << j << std::endl;

  std::pair<char, char> p5 = std::make_pair('x', 'y');
  char c;
  std::tie(std::ignore, c) = p5;
  std::cout << c << std::endl;
}