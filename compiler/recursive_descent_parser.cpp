#include <iostream>
#include <string>

using namespace std;

inline void report_error() {
  throw string("syntax error");
}

string::const_iterator lookahead;

void match(const char& chr) {
  if (*lookahead == chr) {
    lookahead++;
  } else {
    report_error();
  }
}

// S1 -> + S1 S1 | - S1 S1 | a
void S1(){
  switch (*lookahead) {
    case '+':
      match('+'); S1(); S1();
      break;
    case '-':
      match('-'); S1(); S1();
      break;
    case 'a':
      match('a');
      break;
    default:
      report_error();
      throw;
  }
}
void parser1(const string& s) {
  lookahead = s.begin();
  S1();
  if (lookahead != s.end()) {
    report_error();
  }
}

// S2 -> S2 ( S2 ) S2 | e
// S2' -> ( S2' ) S2' | e

void S2() {
  switch (*lookahead) {
    case '(':
      match('(');
      S2();
      match(')');
      S2();
      break;
    default:
      break;
  }
}
void parser2(const string& s) {
  lookahead = s.begin();
  S2();
  if (lookahead != s.end()) {
    report_error();
  }
}

// S3 -> 0 S3 1 | 0 1
// S3' -> 0 A
// A -> 1 | 0 A 1
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
void parser3(const string& s) {
  lookahead = s.begin();
  match('0');
  A();
  if (lookahead != s.end()) {
    report_error();
  }
}

int main() {
  try {
    // parser1("+aaa");
    parser2("()()(())");
    // parser3("00001111");
  } catch (const string& error) {
    cout << error << endl;
  }
}