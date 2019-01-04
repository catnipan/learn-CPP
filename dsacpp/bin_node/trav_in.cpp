#include "../bin_tree.h"
#include "../stack.h"

template <typename T>
template <typename VST>
void BinNode<T>::travIn(VST& visit) {
  travIn_I1(this, visit);
}

template <typename T, typename VST>
void travIn_R(BinNodePosi(T) x, VST& visit) {
  if (!x) return;
  travIn_R(x -> lc, visit);
  visit(x -> data);
  travIn_R(x -> rc, visit);
}

template <typename T>
static void goAlongLeftBranch(BinNodePosi(T) x, Stack<BinNodePosi(T)>& S) {
  while (x) {
    S.push(x);
    x = x -> lc;
  }
}

template <typename T, typename VST>
void travIn_I1(BinNodePosi(T) x, VST& visit) {
  Stack<BinNodePosi(T)> S;
  while (true) {
    goAlongLeftBranch(x, S);
    if (S.empty()) break;
    x = S.pop();
    visit(x -> data);
    x = x -> rc;
  }
}
