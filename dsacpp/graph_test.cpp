#include <iostream>
#include <string>
#include "./graph_matrix.h"

using namespace std;

int main() {
  GraphMatrix<char, string> gm{};
  gm.insert('A'); // 0
  gm.insert('B'); // 1
  gm.insert('C'); // 2
  gm.insert('D'); // 3
  gm.insert('E'); // 4
  gm.insert('F'); // 5
  gm.insert('G'); // 6
  gm.insert('S'); // 7
  gm.insert("sa",1,7,0);
  gm.insert("sd",1,7,3);
  gm.insert("sc",1,7,2);
  gm.insert("db",1,3,1);
  gm.insert("cb",1,2,1);
  gm.insert("ae",1,0,4);
  gm.insert("ac",1,0,2);
  gm.insert("ef",1,4,5);
  gm.insert("eg",1,4,6);
  gm.insert("gf",1,6,5);
  gm.insert("gb",1,6,1);

  // gm.dfs(7);

  // test topological sorting
  GraphMatrix<char, string> tpgraph{};
  tpgraph.insert('A'); // 0
  tpgraph.insert('B'); // 1
  tpgraph.insert('C'); // 2
  tpgraph.insert('D'); // 3
  tpgraph.insert('E'); // 4
  tpgraph.insert('F'); // 5
  tpgraph.insert("ac",1,0,2);
  tpgraph.insert("ad",1,0,3);
  tpgraph.insert("cd",1,2,3);
  tpgraph.insert("bc",1,1,2);
  tpgraph.insert("cf",1,2,5);
  tpgraph.insert("ce",1,2,4);
  tpgraph.insert("ef",1,4,5);

  Stack<char>* s = tpgraph.tSort(2);
  while (!s->empty()) {
    auto d = s->pop();
    cout << d << ">";
  }
  cout << endl;
}