#include <iostream>
#include <string>
#include <map>
#include <ctype.h>

using namespace std;

namespace Tag {
  static const int NUM{256}, ID{257}, TRUE{258}, FALSE{259};
};

struct Token {
public:
  int tag;
  Token(int t): tag(t) {}
};

class Num: public Token  {
  const int value;
public:
  Num(int v): Token(Tag::NUM), value(v) {}
};

class Word: public Token {
public:
  const string lexeme;
  Word(int t, string s): Token(t), lexeme(s) {}
};

class Lexer {
  int line{1};
  char peek = ' ';
  map<string, Word*> words{};
  void reserve(Word* t) {
    words.insert(pair<string, Word*>(t->lexeme, t));
  }
public:
  Lexer() {
    reserve(new Word{Tag::TRUE, "true"});
    reserve(new Word{Tag::FALSE, "false"});
  }
  Token* scan() {
    while (cin >> peek) {
      if (peek == ' ' || peek == '\t') {
        continue;
      } else if (peek == '\n') {
        line++;
      } else {
        break;
      }
    }

    if (isdigit(peek)) {
      int v = 0;
      do {
        v = 10 * v + (peek - '0');
        cin >> peek;
      } while (isdigit(peek));
      return new Num{v};
    }

    if (isalpha(peek)) {
      string s{};
      do {
        s += peek;
        cin >> peek;
      } while (isalnum(peek));

      auto found_word = words.find(s);
      if (found_word != words.end()) {
        return found_word->second;
      }

      auto new_word = new Word{Tag::ID, s};
      words.insert(pair<string, Word*>(s, new_word));
      return new_word;
    }

    Token* t = new Token(peek);
    peek = ' ';
    return t;
  }
};

int main() {
  Lexer lx{};
  while (true) {
    auto tk = lx.scan();
    cout << "new token of type " << tk->tag << endl;
  }
}