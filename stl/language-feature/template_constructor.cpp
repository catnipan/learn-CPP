#include <iostream>

template <typename T>
class MyClass {
private:
  T value;
public:
  MyClass(const T& t): value(t) {}

  template <typename U>
  MyClass(const MyClass<U>& u) {
    std::cout << "use template copy constructor" << std::endl;
    value = u.getValue();
  }

  template <typename X>
  void assign(const MyClass<X>& x) {
    value = x.getValue();
  }
  T getValue() const {
    return value;
  }
};

int main() {
  MyClass<int> mc(3);
  std::cout << mc.getValue() << std::endl;

  MyClass<int> mc2(4);
  mc.assign(mc2);
  std::cout << mc.getValue() << std::endl;

  MyClass<float> mc3(5.0);
  mc.assign(mc3);
  std::cout << mc3.getValue() << std::endl;

  MyClass<float> mc4(6.0);
  mc = mc4;
  std::cout << mc.getValue() << std::endl;
}