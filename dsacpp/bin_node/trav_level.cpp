#include "../bin_node.h"
#include "../queue.h"

template <typename T>
template <typename VST>
void BinNode<T>::travLevel(VST& visit) {
  Queue<BinNodePosi(T)> Q;
  Q.enqueue(this);
  while (!Q.empty()) {
    BinNodePosi(T) x = Q.dequeue();
    visit(x -> data);
    if (HasLChild(*x)) Q.enqueue(x -> lc);
    if (HasRChild(*x)) Q.enqueue(x -> rc);
  }
};
