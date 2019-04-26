#include <chrono>
#include <iostream>
#include <string>

class Timer {
  std::chrono::high_resolution_clock::time_point start;
  std::string name;
public:
  Timer(const std::string& name)
    : start(std::chrono::high_resolution_clock::now()), name(name) {}
  void end() {
    auto diff = std::chrono::high_resolution_clock::now() - start;
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(diff);
    std::cout << name << ": " << ms.count() << " ms" << std::endl;
  }
};

