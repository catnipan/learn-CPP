#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

int main() {
  shared_ptr<string> pNico(new string("nico"));
  shared_ptr<string> pJutta(new string("jutta"));

  (*pNico)[0] = 'N';
  pJutta->replace(0, 1, "J");

  vector<shared_ptr<string>> whoMadeCoffee;
  whoMadeCoffee.push_back(pJutta);
  whoMadeCoffee.push_back(pJutta);
  whoMadeCoffee.push_back(pNico);
  whoMadeCoffee.push_back(pJutta);
  whoMadeCoffee.push_back(pNico);

  for (auto ptr: whoMadeCoffee) {
    cout << *ptr << " ";
  }
  cout << endl;

  cout << "-----------" << endl;

  *pNico = "Nicolai";
  for (auto ptr: whoMadeCoffee) {
    cout << *ptr << " ";
  }
  cout << endl;

  cout << "use count: " << whoMadeCoffee[0].use_count() << endl;

  shared_ptr<string> pNico4;
  // pNico4 = new string("nico4"); // error!
  pNico4.reset(new string("nico4"));

  cout << "use count:" << pNico.use_count() << endl;
  whoMadeCoffee.resize(2);
  cout << "use count:" << pNico.use_count() << endl;

  shared_ptr<string> pNico5(
    new string("nico5"),
    [](string* p) {
      cout << "delete " << *p << endl;
      delete p;
    }
  );
  // pNico5 = nullptr;
  // or
  pNico5.reset();

  shared_ptr<int> p(
    new int[10],
    [](int* p) {
      cout << "delete *int[10]" << endl;
      delete [] p;
    }
  );

  shared_ptr<int> pp(
    new int[10],
    default_delete<int[]>()
  );
  // shared_ptr<int[]> ppp(new int[10]); // is not allowed
  unique_ptr<int []> ppp(new int[10]); // allowed
  unique_ptr<int [], void(*)(int *)> pppp(
    new int[10],
    [](int* p) {
      cout << "delete pppp" << endl;
      delete [] p;
    }
  );
}