#pragma once

#include "./list.h"

template <typename T>
class Queue: public List<T> {
public:
  Queue(): List<T>() {  };
  Queue(std::initializer_list<T> il): List<T>(il) {  };
  ListNodePosi(T) enqueue(T const& e) {
    return this->insertAsLast(e);
  }
  T dequeue() {
    return this->remove(this->first());
  }
};
