#include <iostream>
#include <bitset>
#include <set>

using namespace std;

template <size_t n>
class LessThan {
public:
  bool operator()(const bitset<n>& bt1, const bitset<n>& bt2) {
    for (int i = n-1; i >= 0; i--) {
      if (bt1[i] < bt2[i]) {
        return true;
      } else if (bt1[i] > bt2[i]) {
        return false;
      }
    }
    return false;
  }
};

int main() {

  bitset<3> bt1{};
  bt1.set(0, true);
  cout << "bt1:\t" << bt1 << endl;

  bitset<3> bt2{};
  bt2.set(1, true);
  cout << "bt2:\t" << bt2 << endl;

  cout << (LessThan<3>()(bt1, bt2) ? "true" : "false") << endl;

  set<bitset<3>, LessThan<3>> sbs{};
  sbs.insert(bt1);
  auto fd = sbs.find(bt1);
  cout << (fd == sbs.end() ? "not found" : "found") << endl;
  // if (fd !== sbs.cend()) {
  //   cout << *fd << endl;
  // }
}