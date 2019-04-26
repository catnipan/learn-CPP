#include <chrono>
#include <thread>
#include "clock.hpp"
#include "timer.h"

int main() {
  using namespace std;

  cout << "system_clock: " << endl;
  printClockData<chrono::system_clock>();

  cout << "high_resolution_clock: " << endl;
  printClockData<chrono::high_resolution_clock>();

  cout << "steady_clock: " << endl;
  printClockData<chrono::steady_clock>(); 

  Timer t1("test timer");
  this_thread::sleep_for(chrono::milliseconds(1024));
  t1.end();

  Timer t2("loop timer");
  int j = 1;
  for (int i = 0; i < 21332321; i++) {
    j += i;
  }
  cout << endl;
  t2.end();
}