#include <chrono>
#include <ctime>
#include <string>
#include <iostream>

std::string asString(const std::chrono::system_clock::time_point& tp) {
  std::time_t t = std::chrono::system_clock::to_time_t(tp);
  std::string ts = std::ctime(&t);
  ts.resize(ts.size() - 1);
  return ts;
}

int main() {
  std::chrono::system_clock::time_point tp;
  std::cout << "epoch:\t" << asString(tp) << std::endl;

  tp = std::chrono::system_clock::now();
  std::cout << "now:\t" << asString(tp) << std::endl;

  tp = std::chrono::system_clock::time_point::min();
  std::cout << "min:\t" << asString(tp) << std::endl;

  tp = std::chrono::system_clock::time_point::max();
  std::cout << "max:\t" << asString(tp) << std::endl;
}