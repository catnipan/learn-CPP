#include "../bin_tree.h"
#include "../stack.h"

template <typename T>
template <typename VST>
void BinNode<T>::travPost(VST& visit) {
  travPost_I(this, visit);
};

template <typename T, typename VST>
void travPost_R(BinNodePosi(T) x, VST& visit) {
  if (!x) return;
  travPost_R(x -> lc, visit);
  travPost_R(x -> rc, visit);
  visit(x -> data);
}

template <typename T>
static void gotoHLVFL(Stack<BinNodePosi(T)>& S) {
  while (BinNodePosi(T) x = S.top()) {
    if (HasLChild(*x)) {
      if (HasRChild(*x)) {
        S.push(x -> rc);
      }
      S.push(x -> lc);
    } else {
      S.push(x -> rc);
    }
  }
  S.pop();
}

template <typename T, typename VST>
void travPost_I(BinNodePosi(T) x, VST& visit) {
  Stack<BinNodePosi(T)> S;
  if (x) S.push(x);
  while (!S.empty()) {
    if (S.top() != x -> parent) {
      gotoHLVFL(S);
    }
    x = S.pop();
    visit(x -> data);
  }
}