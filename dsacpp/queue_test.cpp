#include <iostream>
#include "./queue.h"

using namespace std;

int main() {
  
  Queue<int> que;

  que.enqueue(3);
  que.enqueue(4);
  que.enqueue(5);

  cout << que.dequeue() << endl;
  cout << que.dequeue() << endl;
  cout << que.dequeue() << endl;
}