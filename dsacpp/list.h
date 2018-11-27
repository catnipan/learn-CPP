#pragma once

#include <initializer_list>
#include "./list_node.h"

template <typename T> class List {
private:
  int _size;
  ListNodePosi(T) header;
  ListNodePosi(T) trailer;

protected:
  void init();
  int clear();
  void copyNodes(ListNodePosi(T), int);
  void merge(ListNodePosi(T)&, int, List<T>&, ListNodePosi(T), int);
  void mergeSort(ListNodePosi(T)&, int);
  void selectionSort(ListNodePosi(T), int);
  void insertionSort(ListNodePosi(T), int);

public:
  List() { init(); }
  List(List<T> const& L);
  List(List<T> const& L, Rank r, int n);
  List(ListNodePosi(T) p, int n);
  List(std::initializer_list<T> il);

  ~List();

  Rank size() const { return _size; }
  bool empty() const { return _size <= 0; }
  T& operator[] (Rank r) const;
  ListNodePosi(T) first() const { return header->succ; }
  ListNodePosi(T) last() const { return trailer->pred; }
  bool valid(ListNodePosi(T) p) {
    return p && (trailer != p) && (header != p);
  }
  int disordered() const;
  ListNodePosi(T) find(T const& e) const {
    return find(e, _size, trailer);
  }
  ListNodePosi(T) find(T const& e, int n, ListNodePosi(T) p) const;
  ListNodePosi(T) search(T const& e) const {
    return search(e, _size, trailer);
  }
  ListNodePosi(T) search(T const& e, int n, ListNodePosi(T) p) const;
  ListNodePosi(T) selectMax(ListNodePosi(T) p, int n);
  ListNodePosi(T) selectMax() {
    return selectMax(header->succ, _size);
  }

  ListNodePosi(T) insertAsFirst(T const& e);
  ListNodePosi(T) insertAsLast(T const& e);
  ListNodePosi(T) insertAfter(ListNodePosi(T) p, T const& e);
  ListNodePosi(T) insertBefore(ListNodePosi(T) p, T const& e);
  T remove(ListNodePosi(T) p);
  void merge(List<T>& L) {
    merge(first(), _size, L, L.first, L._size);
  }
  void sort(ListNodePosi(T) p, int n);
  void sort() { sort(first(), _size); }
  int deduplicate();
  int uniquify();
  void reverse();

  template <typename S>
  friend List<S> mconcat(const List<List<S>>& ls);
  template <typename S> List<S> map(S (*) (const T&));
  template <typename S> List<S> flatMap(List<S> (*) (const T&));
  void traverse(void (*) (T&));
  template <typename VST> void traverse(VST&);
  void show();
};

#include "list/bracket.cpp"
#include "list/clear.cpp"
#include "list/constructor.cpp"
#include "list/copyNodes.cpp"
#include "list/destruct.cpp"
#include "list/deduplicate.cpp"
#include "list/find.cpp"
#include "list/flatMap.cpp"
#include "list/map.cpp"
#include "list/init.cpp"
#include "list/insert.cpp"
#include "list/remove.cpp"
#include "list/show.cpp"
#include "list/traverse.cpp"
