#include <iostream>
#include <string>
#include "./parser.h"

using namespace std;

class I2P_Parser: public Parser {
public:
  string convert(const string& s) {
    this->run(s);
    return outcome;
  }
private:
  string outcome;
  void print(const char& chr) {
    outcome += chr;
  }
  virtual void parse(const string& s) {
    outcome = "";
    term();
    rest();
  }
  void rest() {
    switch (*lookahead)
    {
      case '+':
        match('+');
        term();
        print('+');
        rest();
        break;
      case '-':
        match('-');
        term();
        print('-');
        rest();
        break;
      default:
        break;
    }
  }
  void term() {
    switch (*lookahead)
    {
      case '0': match('0'); print('0'); break;
      case '1': match('1'); print('1'); break;
      case '2': match('2'); print('2'); break;
      case '3': match('3'); print('3'); break;
      case '4': match('4'); print('4'); break;
      case '5': match('5'); print('5'); break;
      case '6': match('6'); print('6'); break;
      case '7': match('7'); print('7'); break;
      case '8': match('8'); print('8'); break;
      case '9': match('9'); print('9'); break;
      default:
        break;
    }
  }
};

int main() {
  I2P_Parser i2p{};
  cout << i2p.convert("2+3-4") << endl;
  cout << i2p.convert("2--54") << endl;
  cout << i2p.convert("4-3+6") << endl;
}