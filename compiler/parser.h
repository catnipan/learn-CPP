#pragma once

#include <iostream>
#include <string>

class Parser {
public:
  void run(const std::string& s) {
    lookahead = s.begin();
    try {
      parse(s);
      if (lookahead != s.end()) {
        report_error();
      }
      std::cout << "parse '" << s << "' : ok" << std::endl;
    } catch (const std::string& err) {
      std::cout << "parse '" << s << "' : " << err << std::endl;
    }
  }
protected:
  virtual void parse(const std::string& s) = 0;
  std::string::const_iterator lookahead;
  void report_error() {
    throw std::string("syntax error");
  }
  void match(const char& chr) {
    if (*lookahead == chr) {
      lookahead++;
    } else {
      report_error();
    }
  }
};