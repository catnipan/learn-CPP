#include <iostream>

using namespace std;

class Base {
public:
  virtual void print() {
    cout << "print call from base class" << endl;
  }
  void show() {
    cout << "show call from base class" << endl;
  }
};

class Derived: public Base {
public:
  void print() {
    cout << "print called from derived class" << endl;
  }
  void show() {
    cout << "show called from derived class" << endl;
  }
};

int main() {
  Base* some_ptr;
  Derived d;
  some_ptr = &d;
  some_ptr->print();
  some_ptr->show();
}