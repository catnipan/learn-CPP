#include <iostream>
#include <string>
#include "./parser.h"

using namespace std;

// S -> + S S | - S S | a
class Parser1: public Parser {
private:
  virtual void parse(const string& s) {
    S();
  }
  void S(){
    switch (*lookahead) {
      case '+':
        match('+'); S(); S();
        break;
      case '-':
        match('-'); S(); S();
        break;
      case 'a':
        match('a');
        break;
      default:
        report_error();
        throw;
    }
  }
};

// S -> S ( S ) S | e
// S' -> ( S' ) S' | e
class Parser2: public Parser {
private:
  virtual void parse(const string& s) {
    S();
  }
  void S() {
   switch (*lookahead) {
      case '(':
        match('(');
        S();
        match(')');
        S();
        break;
      default:
        break;
    }
  }
};

// S -> 0 S 1 | 0 1
// S' -> 0 A
// A -> 1 | 0 A 1
class Parser3: public Parser {
private:
  virtual void parse(const string& s) {
    S();
  }
  void S() {
    match('0');
    A();
  }
  void A() {
    switch (*lookahead)
    {
      case '1':
        match('1');
        break;
      case '0':
        match('0');
        A();
        match('1');
        break;
      default:
        report_error();
        break;
    }
  }
};

int main() {
  Parser1 p1{};
  p1.run("+aa");
  p1.run("+aaa");
  p1.run("+a-aa");

  Parser2 p2{};
  p2.run("(())()()");
  p2.run("(()())");
  p2.run("()())");
  p2.run("()(");

  Parser3 p3{};
  p3.run("001");
  p3.run("01");
  p3.run("000111");
  p3.run("0111");
}