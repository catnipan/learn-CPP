#include "../bin_node.h"
#include "../stack.h"

template <typename T>
template <typename VST>
void BinNode<T>::travPre(VST& visit) {
  travPre_I2(this, visit);
}

template <typename T, typename VST>
void travPre_R(BinNodePosi(T) x, VST& visit) {
  if (!x) return;
  visit(x -> data);
  travPre_R(x -> lc, visit);
  travPre_R(x -> rc, visit);
}

template <typename T, typename VST>
static void visitAlongLeftBranch(BinNodePosi(T) x, VST& visit, Stack<BinNodePosi(T)>& S) {
  while (x) {
    visit(x -> data);
    S.push(x -> rc);
    x = x -> lc;
  }
}

template <typename T, typename VST>
void travPre_I2(BinNodePosi(T) x, VST& visit) {
  Stack<BinNodePosi(T)> S;
  while (true) {
    visitAlongLeftBranch(x, visit, S);
    if (S.empty()) break;
    x = S.pop();
  }
}
