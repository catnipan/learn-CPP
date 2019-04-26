#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;
using namespace std::chrono;

template <typename V, typename R>
ostream& operator<<(ostream& s, const chrono::duration<V,R>& d) {
  s << "[" << d.count() << " of " << R::num << "/" << R::den << "]";
  return s;
}

int main() {
  seconds twentySeconds(20);
  hours aDay(24);
  milliseconds ms(0);
  cout << ms.count() << " ms" << endl;
  ms += twentySeconds + aDay;
  cout << ms.count() << " ms" << endl;
  --ms;
  cout << ms.count() << " ms" << endl;
  ms *= 2;
  cout << ms.count() << " ms" << endl;

  cout << nanoseconds(ms).count() << " ns" << endl;

  cout << "--------------" << endl;

  milliseconds d(42);
  cout << d << endl;

  seconds sec(55);
  // minutes m1 = sec; //  ERROR
  minutes m2 = duration_cast<minutes>(sec);
  cout << m2.count() << " min" << endl;

  duration<double, std::ratio<60>> halfMin(0.5);
  seconds s2 = duration_cast<seconds>(halfMin);
  cout << s2.count() << " s" << endl;

  cout << "--------------" << endl;

  milliseconds ms1(7255042);
  hours hh = duration_cast<hours>(ms1);
  minutes mm = duration_cast<minutes> (ms1 % hours(1));
  seconds ss = duration_cast<seconds> (ms1 % minutes(1));
  milliseconds msec = duration_cast<milliseconds>(ms1 % seconds(1));

  cout << "raw: " << hh << "::" << mm << "::" << ss << "::" << msec << endl;
  cout << "     " << setfill('0') << setw(2) << hh.count() << "::"
                                  << setw(2) << mm.count() << "::"
                                  << setw(2) << ss.count() << "::"
                                  << setw(3) << msec.count() << endl;
}