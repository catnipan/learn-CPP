#pragma once

#include "./vector.h"

template <typename T>
class Stack: public Vector<T> {
private:
  Rank getTopRank() {
    return this->size() - 1;
  }
public:
  Stack(): Vector<T>() {  };
  Stack(std::initializer_list<T> il): Vector<T>(il) {  };
  Stack<T>& push(T const& e) {
    this->insert(e);
    return *this;
  }
  T pop() {
    return this->remove(getTopRank());
  }
  T& top() {
    return (*this)[getTopRank()];
  }
};

#include "stack/ostream.cpp"
